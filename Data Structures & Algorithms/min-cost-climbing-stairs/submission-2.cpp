class Solution {
    vector<int> dp;
    int n;
    int rec(int idx, vector<int>& cost) {
        if (idx >= n) {
            return 0;
        }

        if (dp[idx] != INT_MAX) {
            return dp[idx];
        }

        int one = cost[idx] + rec(idx + 1, cost);
        int two = cost[idx] + rec(idx + 2, cost);

        return dp[idx] = min(one, two);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        dp.resize(n, INT_MAX);

        return min(rec(0, cost), rec(1, cost));
    }
};
