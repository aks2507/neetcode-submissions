class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.length(), m = t.length(), i = 0, j = 0;

        while (i < n) {
            if (s[i] == t[j]) {
                j++;
            }
            i++;
        }

        return m - j > 0 ? m - j : 0;
    }
};