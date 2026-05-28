class Solution {
public:
    bool isInterleaveRec(string s1, string s2, int i1, int i2, string s3, vector<vector<int>>& dp) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        int i3 = i1 + i2;
        if (i1 == n1 && i2 == n2 && i3 == n3) {
            return true;
        }

        if (dp[i1][i2] != -1) {
            return dp[i1][i2];
        }

        bool res = false;

        if (i1 < n1) {
            res = res || (s1[i1] == s3[i3] && isInterleaveRec(s1, s2, i1 + 1, i2, s3, dp));
        }

        if (i2 < n2) {
            res = res || (s2[i2] == s3[i3] && isInterleaveRec(s1, s2, i1, i2 + 1, s3, dp));
        }

        dp[i1][i2] = res;

        return dp[i1][i2];
    }
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }

        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        return isInterleaveRec(s1, s2, 0, 0, s3, dp);
    }
};
