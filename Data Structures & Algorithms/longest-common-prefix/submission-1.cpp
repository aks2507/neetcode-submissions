class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) {
            return "";
        }

        for(int i = 0; i < strs[0].length(); i++) {
            for(string s : strs) {
                if(i == s.length() || s[i] != strs[0][i]) {
                    return s.substr(0, i);
                }
            }
        }

        return strs[0];
    }
};