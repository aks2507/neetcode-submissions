class Solution {
    bool isAlphaNum(char c) {
        return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    char lowercased(char c) {
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')) return c;
        
        return c -'A' + 'a';
    }
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (isAlphaNum(s[l]) && isAlphaNum(s[r]) && lowercased(s[l]) != lowercased(s[r])) {
                return false;
            }
            if (isAlphaNum(s[l]) && isAlphaNum(s[r]) && lowercased(s[l]) == lowercased(s[r])) {
                l++;
                r--;
            } else if (!isAlphaNum(s[l])) {
                l++;
            } else if (!isAlphaNum(s[r])) {
                r--;
            }
        }

        return true;
    }
};
