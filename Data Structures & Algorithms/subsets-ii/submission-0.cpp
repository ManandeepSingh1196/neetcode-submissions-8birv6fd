class Solution {
public: 
    vector<vector<int>> res;

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subset;
        sort(nums.begin(), nums.end());
        backtracking(nums, 0, subset);
        return res;
    }

private:
    void backtracking(const vector<int>& nums, int i, vector<int>& subset)
    {
        if (i == nums.size())  
        {
            res.push_back(subset);
            return;
        }
        
        subset.push_back(nums[i]);
        backtracking(nums, i + 1, subset);
        subset.pop_back();

        while (i + 1 < nums.size() && nums[i] == nums[i + 1])   i++;

        backtracking(nums, i + 1, subset);
    }
};
