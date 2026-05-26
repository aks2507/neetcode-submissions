class Solution {
public:
    int dp(vector<int>& prices, vector<vector<int>>& idx_avail, int idx, bool coinAvailable) {
        if (idx >= prices.size()) {
            return 0;
        }

        if (idx_avail[idx][coinAvailable] != -1) {
            return idx_avail[idx][coinAvailable];
        }

        int nothing = dp(prices, idx_avail, idx + 1, coinAvailable);
        int res = 0;
        if (coinAvailable) {
            res = dp(prices, idx_avail, idx + 2, !coinAvailable) + prices[idx];
        } else {
            res = dp(prices, idx_avail, idx + 1, !coinAvailable) - prices[idx];
        }

        idx_avail[idx][coinAvailable] = max(nothing, res);
        return idx_avail[idx][coinAvailable];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) {
            return 0;
        }

        vector<vector<int>> idx_avail(n, vector<int>(2, -1));

        int idx = 0, coinAvailable = false;
        int res = dp(prices, idx_avail, idx, coinAvailable);

        return res;
    }
};
