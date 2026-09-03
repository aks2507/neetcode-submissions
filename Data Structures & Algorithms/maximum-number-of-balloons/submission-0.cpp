class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26, 0);

        for (char c : text) {
            freq[c - 'a']++;
        }

        return min(freq['b' - 'a'], min(freq['a' - 'a'], min(freq['n' - 'a'], min(freq['l' - 'a'] / 2, freq['o' - 'a'] / 2))));
    }
};