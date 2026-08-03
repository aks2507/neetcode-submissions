class Solution {
private:
    unordered_map<char, vector<char>> digitToChars = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}},
    };

    vector<string> res;

    void allComb(string digits, string tillNow, int idx) {
        if (tillNow.length() == digits.length()) {
            res.push_back(tillNow);
            return;
        }

        vector<char> chars = digitToChars[digits[idx]];

        for (auto& s : chars) {
            tillNow += s;
            allComb(digits, tillNow, idx + 1);
            tillNow.pop_back();
        }
    } 
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) {
            return vector<string>(0);
        }
        allComb(digits, "", 0);
        return res;
    }
};
