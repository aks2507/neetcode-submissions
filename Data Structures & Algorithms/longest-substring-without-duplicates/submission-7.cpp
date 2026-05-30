class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0) {
            return 0;
        }
        unordered_map<char, int> m;
        int l = 0, r = 0;
        int mlen = 0;

        while(r < n) {
            if (m.count(s[r])) {
                l = max(m[s[r]] + 1, l);
            } 
            
            mlen = max(mlen, r - l + 1);
            m[s[r]] = r;
            r++;
        }

        return mlen;
    }
};
