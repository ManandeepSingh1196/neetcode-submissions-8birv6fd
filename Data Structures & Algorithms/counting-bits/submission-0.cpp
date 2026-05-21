class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result; result.reserve(n);

        for (int idx = 0; idx <= n; ++idx)
            result.push_back(__builtin_popcount(idx));

        return result;
    }
};
