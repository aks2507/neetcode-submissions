class Solution {
private:
    bool isPalindrome(string s) {
        int n = s.length();
        if (n == 0) {
            return false;
        }

        int l = 0, r = n - 1;
        while(l <= r) {
            if(s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }

        return true;
    }
    void allPals(int startIdx, int endIdx, string s, vector<string> pals, vector<vector<string>>& res) {
        if (endIdx >= s.length()) {
            if (startIdx == endIdx) {
                res.push_back(pals);
            }
            return;
        }

        string wordNow = s.substr(startIdx, endIdx - startIdx + 1);
        if (isPalindrome(wordNow)) {
            pals.push_back(wordNow);
            allPals(endIdx + 1, endIdx + 1, s, pals, res);
            pals.pop_back();
        }

        allPals(startIdx, endIdx + 1, s, pals, res);
        
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> pals;
        allPals(0, 0, s, pals, res);
        return res;
    }
};
