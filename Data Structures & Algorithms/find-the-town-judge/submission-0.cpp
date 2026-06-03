class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustFlow(n + 1, 0);

        for (auto& person : trust)
        {
            trustFlow[person[0]]--;
            trustFlow[person[1]]++;
        }

        for (int idx = 1; idx < n + 1; ++idx)
            if (trustFlow[idx] == n - 1)
                return idx;
        
        return -1;
    }
};