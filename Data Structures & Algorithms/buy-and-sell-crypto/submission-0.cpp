class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0; int minPrice = 0xFFFF;

        for (int currentPrice : prices)
        {
            minPrice = min(currentPrice, minPrice);
            maxProfit = max(maxProfit, currentPrice - minPrice);
        }

        return maxProfit;
    }
};
