class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int idxNow = 0;
        unordered_map<char, int> mp;
        for (int i = 0; i < 26; i++) {
            mp[keyboard[i]] = i; 
        }
        int totalTime = 0;
        for (char c : word) {
            int idx = mp[c];
            totalTime += abs(idx - idxNow);
            idxNow = idx;
        }

        return totalTime;
    }
};
