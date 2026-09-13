class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> st;

        int l = 0, maxlen = 0;
        for (int r = 0; r < n; r++) {
            while (st.count(s[r])) {
                st.erase(s[l]);
                l++;
            }

            st.insert(s[r]);
            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};
