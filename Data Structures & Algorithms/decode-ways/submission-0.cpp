class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp (s.size() + 1);
        dp[s.size()] = 1;

        for (int idx = s.size() - 1; idx >= 0; --idx)
            if (s[idx] == '0') dp[idx] = 0;
            else
            {
                dp[idx] = dp[idx + 1];

                if (idx + 1 < s.size()                  && 
                    (s[idx] == '1' || s[idx] == '2'     &&
                    s[idx + 1] < '7'))
                
                    dp[idx] += dp[idx + 2];
            }

            return dp[0];
    }
};
