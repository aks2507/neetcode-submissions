class Solution {
public:
    int timeTaken(int bananas, int rate) {
        return (bananas % rate == 0) ? (bananas / rate) : (bananas / rate) + 1;
    }

    int totalTime(vector<int>& piles, int rate) {
        int res = 0;
        for(int i = 0; i < piles.size(); i++) {
            res += timeTaken(piles[i], rate);
        }

        return res;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = *max_element(piles.begin(), piles.end());

        int l = 1, r = max;
        int res = r;
        while (l <= r) {
            int mid = (l + r) / 2;
            if(totalTime(piles, mid) <= h) {
                res = mid;
                r = mid - 1;
            } else if(totalTime(piles, mid) > h) {
                l = mid + 1;
            }
        }

        return res;
    }
};
