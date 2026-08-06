class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, char> smp, tmp;

        for (int i = 0; i < s.length(); i++) {
            if ((smp.count(s[i]) && smp[s[i]] != t[i]) || 
                (tmp.count(t[i]) && tmp[t[i]] != s[i])) {
                return false;
            }

            smp[s[i]] = t[i];
            tmp[t[i]] = s[i];
        }

        return true;
    }
};