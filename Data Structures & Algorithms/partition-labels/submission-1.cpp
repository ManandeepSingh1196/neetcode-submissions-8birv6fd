class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res; 
        unordered_map<char, int> last;
        for (int idx = 0; idx < s.size(); ++idx)
            last[s[idx]] = idx;

        int size = 0; int end = 0;
        for (int idx = 0; idx < s.size(); ++idx)
        {
            size++;
            end = max(end, last[s[idx]]);

            if (idx == end)
            {
                res.push_back(size);
                size = 0;
            }
        }

        return res;
    }
};
