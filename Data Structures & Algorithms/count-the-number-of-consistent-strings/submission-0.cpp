class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> check(allowed.begin(), allowed.end());
        int res = 0;
        for (string word : words) {
            bool consistent = true;
            for (char c : word) {
                if (!check.count(c)) {
                    consistent = false;
                    break;
                }
            }

            res += consistent;
        }

        return res;
    }
};