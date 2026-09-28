class Solution {
public:
    int countOdds(int low, int high) {
        if (low == high) {
            return low % 2 == 1;
        }
        int count = 0;
        count += ((low % 2 == 1) && (high % 2 == 1));
        count += (high - low + 1) / 2;

        return count;
    }
};