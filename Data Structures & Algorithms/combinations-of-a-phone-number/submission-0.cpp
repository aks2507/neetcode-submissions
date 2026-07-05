class Solution {
private:
    unordered_map<char, vector<char>> numToLetter = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };

    void allCombinations(int idx, string& wordNow, string digits, vector<string>& res) {
        if(idx >= digits.length()) {
            res.push_back(wordNow);
            return;
        }

        auto& chars = numToLetter[digits[idx]];
        for (int i = 0; i < chars.size(); i++) {
            wordNow += chars[i];
            allCombinations(idx + 1, wordNow, digits, res);
            wordNow.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) {
            return vector<string>(0);
        }

        vector<string> res;
        string wordNow = "";
        allCombinations(0, wordNow, digits, res);

        return res;

    }
};
