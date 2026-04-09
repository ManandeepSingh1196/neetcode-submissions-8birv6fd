typedef vector<vector<int>> vv;

class Solution {
public: 
    vv result;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> subset;

        backtracking(target, 0, subset, nums);
        return result;
    }

public: 
    void backtracking(int target, const int i, vector<int>& subset, const vector<int>& nums)
    {
        if (i >= nums.size() || target < 0) return; 
        if (target == 0)
        {
            result.push_back(subset);  
            return;
        }

        subset.push_back(nums[i]);
        backtracking(target - nums[i], i, subset, nums);
        subset.pop_back();
        backtracking(target, i + 1, subset, nums);
    }
};
