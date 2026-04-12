#include<cstring>

class Solution {
public: 
    int cache[46];
    
public:
    int climbStairs(int n) {
        memset(cache, -1, sizeof(cache));
    
        return backtracking(n, 0);
    }

private: 
    int backtracking(int n, int idx)
    {
        if (idx >= n) return idx == n;

        if (cache[idx] != -1) return cache[idx];
        return cache[idx] = backtracking(n, idx + 1) + backtracking(n, idx + 2);
    }
};
