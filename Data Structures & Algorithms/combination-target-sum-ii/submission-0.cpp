class Solution {
public:
    vector<vector<int>> res;

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur;

        dfs(candidates, target, 0, cur);
        return res;
    }

private:
    void dfs(vector<int>& candidates, int target, int i, vector<int>& cur) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        if (target < 0 || i == candidates.size()) {
            return;
        }

        cur.push_back(candidates[i]);
        dfs(candidates, target - candidates[i], i + 1, cur);
        cur.pop_back();

        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
            i++;
        }
        dfs(candidates, target, i + 1, cur);
    }
};