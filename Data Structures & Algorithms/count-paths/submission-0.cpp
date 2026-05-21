class Solution {
public:
    int dpPaths(vector<vector<int>>& dp, int i, int j, int m, int n) {
        if (i >= m || j >= n) {
            return 0;
        }
        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        if (dp[i][j] != 0) {
            return dp[i][j];
        }

        int res = 0;
        if (i + 1 <= m - 1) {
            res += dpPaths(dp, i + 1, j, m , n);
        }

        if (j + 1 <= n - 1) {
            res += dpPaths(dp, i, j + 1, m , n);
        }

        dp[i][j] = res;
        return res;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        if (m == 0 || n == 0) {
            return 1;
        }
        return dpPaths(dp, 0, 0, m, n);
    }
};
