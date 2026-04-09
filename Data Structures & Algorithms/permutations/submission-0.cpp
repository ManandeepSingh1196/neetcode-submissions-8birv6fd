class Solution {
public:
    vector<vector<int>> result;

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> subset;
        vector<bool> used(nums.size(), false);

        backtracking(nums, subset, used);
        return result;
    }

private:
    void backtracking(vector<int>& nums, vector<int>& subset, vector<bool>& used) {
        if (subset.size() == nums.size()) {
            result.push_back(subset);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            subset.push_back(nums[i]);
            used[i] = true;

            backtracking(nums, subset, used);

            subset.pop_back();
            used[i] = false;
        }
    }
};