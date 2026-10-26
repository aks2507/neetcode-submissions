class Solution {
    long long totalTimeTaken(int rate, vector<int>& piles) {
        long long sum = 0;
        for (int& pile : piles) {
            sum += (pile % rate == 0) ? pile / rate : pile / rate + 1;
        }

        return sum;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxm = *max_element(piles.begin(), piles.end());

        int l = 1, r = maxm;

        int res = maxm;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (totalTimeTaken(mid, piles) <= h) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return res;
    }
};
