typedef long long ll;
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 0, r = num / 2 + 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            ll sq = (ll) mid * mid;

            if (sq == num) {
                return true;
            } else if (sq < num) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return false;
    }
};