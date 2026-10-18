class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> mp; 
        int maxLen = -1;
        for (int i = 0; i < s.length(); i++) {
            if (!mp.count(s[i])) {
                mp[s[i]] = i;
            } else {
                maxLen = max(maxLen, i - mp[s[i]] - 1);
            }
        }

        return maxLen;
    }
};