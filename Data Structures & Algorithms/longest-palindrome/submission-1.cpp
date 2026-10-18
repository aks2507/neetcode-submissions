class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;

        for (char& c : s) {
            mp[c]++;
        }

        int len = 0, oddFreqExists = 0;
        for (const auto& [c, f] : mp) {
            if (f % 2 == 0) {
                len += f;
            } else {
                oddFreqExists = 1;
                len += f - 1;
            }   
        }

        return len + oddFreqExists;
    }
};