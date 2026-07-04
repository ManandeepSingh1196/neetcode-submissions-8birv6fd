class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp (size, 1000);
        dp[size - 1] = 0;

        for (int i = size - 2; i >= 0; --i)
        {
            int end = min((int)nums.size(), i + nums[i] + 1);
            for (int j = i + 1; j < end; ++j)
                dp[i] = min(dp[i], dp[j] + 1);
        }

        return dp[0];
    }
};
