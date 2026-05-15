class Solution {
public:
    bool correct_char(char c) {
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        if (s.size() == 0 || s.size() == 1) {
            return true;
        }

        int l = 0, r = s.size() - 1;
        while(l < r) {
            cout << "Left: " << s[l] << " AND Right: " << s[r] << endl;
            if (!correct_char(s[l])) {
                cout << "Ignoring space and increasing left" << endl;
                l++;
                continue;
            }

            if(!correct_char(s[r])) {
                cout << "Ignoring space and increasing right" << endl;
                r--;
                continue;
            }

            if (tolower(s[l]) != tolower(s[r])) {
                cout << "Unequality!" << endl;
                return false;
            } else {
                cout << "Equality!" << endl;
                l++;
                r--;
            }
        }
        return true;
    }
};
