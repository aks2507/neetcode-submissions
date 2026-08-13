class Solution {
public:
    int maxDifference(string s) {
        int maxOdd = 0, minEven = s.length();
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        for (int c : freq) {
            if (c % 2 == 1) {
                maxOdd = max(maxOdd, c);
            } else if (c > 0) {
                minEven = min(minEven, c);
            }
        }

        return maxOdd - minEven;
    }
};