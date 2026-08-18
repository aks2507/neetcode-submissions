class Solution {
private:
    vector<string> stringToVec(string s) {
        stringstream ss(s);
        vector<string> res;
        string token;

        while(getline(ss, token, ' ')) {
            res.push_back(token);
        }

        return res;
    }
public:
    bool wordPattern(string pattern, string s) {
        vector<string> vec = stringToVec(s);
        int n = pattern.length();
        if (vec.size() != n) {
            return false;
        }

        unordered_map<string, char> wordToChar;
        unordered_map<char, string> charToWord;

        for(int i = 0; i < n; i++) {
            if ((wordToChar.count(vec[i]) && wordToChar[vec[i]] != pattern[i]) || (charToWord.count(pattern[i]) && charToWord[pattern[i]] != vec[i])) {
                return false;
            }

            wordToChar[vec[i]] = pattern[i];
            charToWord[pattern[i]] = vec[i];
        }

        return true;
    }
};