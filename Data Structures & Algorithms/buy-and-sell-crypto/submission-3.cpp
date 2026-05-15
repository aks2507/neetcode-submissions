class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int sell = 1;
        int curr_profit = 0;
        int n = prices.size();
        while(sell < n) {
            if(prices[sell] < prices[buy]){
                buy = sell;
            }
            if(prices[sell] - prices[buy] > curr_profit)
            {
                curr_profit = prices[sell] - prices[buy];
            }
            sell++;
        }

        return curr_profit;
    }
};
