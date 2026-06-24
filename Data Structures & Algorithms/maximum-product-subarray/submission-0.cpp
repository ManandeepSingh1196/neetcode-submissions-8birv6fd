class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int currMax = 1; int currMin = 1;

        for (int curr : nums)
        {
            int temp = currMax * curr;
            currMax = max(max(temp, curr * currMin), curr);
            currMin = min(min(temp, curr * currMin), curr);
            res = max(res, currMax);
        }

        return res;
    }
};
