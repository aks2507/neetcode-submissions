class Solution {
public:
    // Basic recursion
    // int climb(int n, int i) {
    //     if (i > n) {
    //         return 0;
    //     }

    //     if (i == n) {
    //         return 1;
    //     }

    //     return climb(n, i + 1) + climb(n, i + 2);
    // }

    int dpClimb(int n, int i, vector<int>& dp) {
        if (i > n) {
            return 0;
        }

        if (i == n) {
            return 1;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        dp[i] = dpClimb(n, i + 1, dp) + dpClimb(n, i + 2, dp);
        return dp[i];
    }
    
    int climbStairs(int n) {
        // return climb(n, 0);

        // Using dynamic programming
        vector<int> dp(n, -1);
        return dpClimb(n, 0, dp);
    }
};
