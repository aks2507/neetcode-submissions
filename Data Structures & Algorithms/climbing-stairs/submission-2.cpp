class Solution {
    vector<int> dp;
    int rec(int n) {
        if (n <= 0) {
            return n == 0;
        }
        
        if (dp[n] != -1) {
            return dp[n];
        }
        dp[n] = rec(n - 1) + rec(n - 2);
        return dp[n];
    }
public:
    int climbStairs(int n) {
        dp.resize(n + 1, -1);
        return rec(n);
    }
};
