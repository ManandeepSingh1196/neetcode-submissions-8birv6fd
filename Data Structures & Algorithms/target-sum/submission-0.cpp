class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(0, 0, nums, target);
    }

private: 
    int dfs(int count, int sum, vector<int>& nums, int target)
    {
        if (count == nums.size())   return sum == target;

        return dfs(count + 1, sum + nums[count], nums, target)
             + dfs(count + 1, sum - nums[count], nums, target);
    }
};
