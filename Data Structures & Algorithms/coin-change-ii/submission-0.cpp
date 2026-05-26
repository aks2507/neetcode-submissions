class Solution {
public:
    int dp(int amount, int idx, vector<int>& coins, vector<vector<int>>& mem) {
        if (amount < 0 || idx >= coins.size()) {
            return 0;
        }

        if (amount == 0) {
            return 1;
        }

        if (mem[amount][idx] != -1) {
            return mem[amount][idx];
        }

        int pick = dp(amount - coins[idx], idx, coins, mem);
        int skip = dp(amount, idx + 1, coins, mem);

        mem[amount][idx] = pick + skip;
        return mem[amount][idx];
    }
    int change(int amount, vector<int>& coins) {
        if (coins.size() == 0) {
            return 0;
        }

        vector<vector<int>> mem(amount + 1, vector<int>(coins.size(), -1));
        return dp(amount, 0, coins, mem);
    }
};
