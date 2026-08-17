typedef long long ll; 
class Solution {
private:
    int sqroot(int n) {
        if (n == 0 || n == 1) {
            return n;
        }

        int l = 0, r = n / 2 + 1;
        int res = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            ll sq = (ll) mid * mid;
            if (sq > n) {
                r = mid - 1;
            } else if (sq < n) {
                l = mid + 1;
                res = mid;
            } else {
                return mid;
            }
        }

        return res;
    }
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<ll> maxHeap(gifts.begin(), gifts.end());

        while(k--) {
            ll top = maxHeap.top();
            maxHeap.pop();
            cout << "top now -> " << top << endl;
            top = sqroot(top);
            cout << "top after sq root now -> " << top << endl;
            maxHeap.push(top);
        }

        ll sum = 0;
        while(!maxHeap.empty()) {
            sum += (ll) maxHeap.top();
            maxHeap.pop();
        }

        return sum;
    }
};