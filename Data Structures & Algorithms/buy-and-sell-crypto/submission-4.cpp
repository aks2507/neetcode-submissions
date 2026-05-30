class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1;
        int mProfit = 0;
        while(r < prices.size()) {
            int profit = prices[r] - prices[l];
            
            if (prices[r] < prices[l]) {
                l = r;
            }

            mProfit = max(profit, mProfit);
            r++;
        }

        return mProfit;
    }
};
