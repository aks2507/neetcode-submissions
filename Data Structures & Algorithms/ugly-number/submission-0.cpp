class Solution {
public:
    bool isUgly(int n) {
        if (n < 0) return false;

        vector<int> v = {2, 3, 5};
        for (int k : v) {
            while (n % k == 0) {
                n /= k;
            }
        }

        return n == 1;
    }
};