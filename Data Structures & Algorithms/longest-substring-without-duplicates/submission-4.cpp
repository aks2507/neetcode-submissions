class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> char_indices;
        int l = 0;
        int max_len = 0;
        for(int r = 0; r < s.size(); r++) {
            if(char_indices.find(s[r]) != char_indices.end()) {
                l = max(char_indices[s[r]] + 1, l);
            }
            char_indices[s[r]] = r;
            max_len = max(max_len, r - l + 1);
        }
        return max_len;
    }
};
