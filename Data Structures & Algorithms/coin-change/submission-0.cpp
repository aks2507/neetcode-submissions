class Solution {
public:
    int dpCoinChange(vector<int>& coins, unordered_map<int, int>& dp, int amount) {
        if (amount == 0) {
            return 0;
        }

        if (amount < 0) {
            return INT_MAX;
        }

        if (dp.count(amount)) {
            return dp[amount];
        }

        int res = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int sub = dpCoinChange(coins, dp, amount - coins[i]);

            if (sub != INT_MAX) {
                res = min(res, 1 + dpCoinChange(coins, dp, amount - coins[i]));
            }
        }

        dp[amount] = res;
        return res;

    }
    
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> dp;
        int res = dpCoinChange(coins, dp, amount);

        return res == INT_MAX ? -1 : res;
    }
};
