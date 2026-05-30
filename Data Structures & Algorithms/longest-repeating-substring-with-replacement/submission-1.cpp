class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        unordered_map<char, int> f;
        int l = 0, r = 0, maxf = 0, res = 0;
        while(r < n) {
            f[s[r]]++;
            maxf = max(maxf, f[s[r]]);
            while((r - l + 1) - maxf > k) {
                f[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
            r++;
        }

        return res;
    }
};
