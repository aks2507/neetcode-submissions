class Solution {
public:
    int get_hours(vector<int>& piles, int h) {
        int hours = 0;
        for(int i = 0; i < piles.size(); i++) {
            hours += (piles[i] % h == 0) ? (piles[i] / h) : ((piles[i] / h) + 1);
        }

        return hours;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_pile = piles[0];

        for(int i = 0; i < piles.size(); i++) {
            max_pile = max(max_pile, piles[i]);
        }

        int l = 1, r = max_pile;
        int res = l;
        while (l <= r) {
            int mid = (l + r) / 2;
            int current_hours = get_hours(piles, mid);
            if (current_hours <= h) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return res;
    }
};
