class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        vector<bool> frag(s.length() + 1, false);
        frag[0] = true;

        for (int i = 1; i <= s.length(); i++) {
            for(int j = 0; j < i; j++) {
                if(frag[j] && dict.count(s.substr(j, i - j))) {
                    frag[i] = true;
                    break;
                }
            }
        }

        return frag[s.length()];
    }
};
