class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) {
            return 0;
        }

        int buy = prices[0], maxProfit = 0, n = prices.size();

        for (int i = 1; i < n; i++) {
            int profit = prices[i] - buy;
            if (profit < 0) {
                buy = prices[i];
            }
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};
