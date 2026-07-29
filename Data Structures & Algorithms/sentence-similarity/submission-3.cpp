class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        int n = sentence1.size();
        int m = sentence2.size();

        if (n != m) return false;
        unordered_map<string, unordered_set<string>> mp;
        for (int i = 0; i < similarPairs.size(); i++) {
            mp[similarPairs[i][0]].insert(similarPairs[i][1]);
            mp[similarPairs[i][1]].insert(similarPairs[i][0]);
        }

        for (int i = 0; i < n; i++) {
            string w1 = sentence1[i], w2 = sentence2[i];
            if (w1 == w2) continue;

            if (!mp.count(w1) || !mp[w1].count(w2)) {
                return false;
            }
        }

        return true;
    }
};
