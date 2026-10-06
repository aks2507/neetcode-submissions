class Solution {
public:
    int countLetters(string s) {
        int total = 0;
        int l = 0, r = 0;
        while (r <= s.length()) {
            if (r == s.length() || s[l] != s[r]) {
                int len = r - l;
                total += (len + 1) * len / 2;
                l = r;
            }
            r++;
        }


        return total;
    }
};
