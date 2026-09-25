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
        // return rec(n);

        // Bottom up
        // dp[1] = 1;
        // dp[2] = 2;
        // for (int i = 3; i <= n; i++) {
        //     dp[i] = dp[i - 1] + dp[i - 2];
        // }

        // return dp[n];

        // Space optimized
        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; i++) {
            int sum = first + second;
            first = second;
            second = sum;
        }

        return n == 1 ? 1 : second;
    }
};
