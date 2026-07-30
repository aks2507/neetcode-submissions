class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }

        int mul2 = 0, notmul2 = 0;
        for (const auto& [k, v] : mp) {
            if (v % 2 == 0) mul2++;
            else notmul2++;
        }

        return notmul2 == (s.length() % 2);
    }
};
