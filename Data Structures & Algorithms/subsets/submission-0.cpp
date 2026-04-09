typedef vector<vector<int>> vv;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vv res;
        vector<int> subset;

        helper_dfs(nums, 0, subset, res);
        return res;
    }

public: 
    void helper_dfs (const vector<int> nums, int i, vector<int>& subset, vv& res)
    {
        if (i >= nums.size())
        {
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        helper_dfs(nums, i + 1, subset, res);   // include current choice
        subset.pop_back();
        helper_dfs(nums, i + 1, subset, res);   // exclude current choice
    }
};
