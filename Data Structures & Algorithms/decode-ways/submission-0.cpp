class Solution {
public:
    int dp(string s, vector<int>& ways, int i) {
        int n = s.size();
        if (s[i] == '0' || i > n) {
            return 0;
        }

        if (i == n) {
            return 1;
        }

        if (ways[i] != -1) {
            return ways[i];
        }

        int res = dp(s, ways, i + 1);

        if ((i + 1 <= n - 1) && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
            res += dp(s, ways, i + 2);
        }

        ways[i] = res;
        return ways[i];
    }
    int numDecodings(string s) {
        int n = s.size();

        vector<int> ways(n, -1);

        return dp(s, ways, 0);
    }
};
