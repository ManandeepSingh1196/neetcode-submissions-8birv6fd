class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return solve(nums, 0, memo);
    }

private:
    int solve(vector<int>& nums, int index, vector<int>& memo) {
        if (index >= nums.size()) return 0;

        if (memo[index] != -1) return memo[index];

        int take = nums[index] + solve(nums, index + 2, memo);
        int skip = solve(nums, index + 1, memo);

        return memo[index] = max(take, skip);
    }
};