class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int recolors = 0, minRecolors = INT_MAX;

        int l = 0, r = 0, n = blocks.length();
        while(r < n) {
            if (blocks[r] == 'W') {
                recolors++;
            }
            r++;
            if (r - l == k) {
                minRecolors = min(minRecolors, recolors);
                if (blocks[l] == 'W') {
                    recolors--;
                }
                l++;
            }
        }

        return minRecolors;
    }
};