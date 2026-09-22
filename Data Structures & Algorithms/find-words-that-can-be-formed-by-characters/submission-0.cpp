class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> charMap;

        for (char c : chars) {
            charMap[c]++;
        }

        int res = 0;
        for (string word : words) {
            unordered_map<char, int> tmp(charMap.begin(), charMap.end());
            bool all = true;
            for (char c : word) {
                tmp[c]--;
                if (tmp[c] < 0) {
                    all = false;
                    break;
                }
            }

            if (all) {
                res += word.length();
            }
        }

        return res;
    }
};