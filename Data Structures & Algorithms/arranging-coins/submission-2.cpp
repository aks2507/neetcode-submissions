typedef long long ll;
class Solution {
    ll sum(int n) {
        if (n == 1) return 1LL;
        return (ll) n * (n + 1) / 2;
    }
public:
    int arrangeCoins(int n) {
        if (n == 1 || n == 2) return 1;
        if (n == 3) return 2;

        int l = 0, r = n / 2 + 1, ans = 1;
        while (l <= r) {
            int mid = (l + r) / 2;

            ll s = sum(mid);
            if (s <= (ll) n) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }   
};