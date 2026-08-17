typedef long long ll; 
class Solution {
// private:
//     int sqroot(int n) {
//         if (n == 0 || n == 1) {
//             return n;
//         }

//         int l = 0, r = n / 2 + 1;
//         int res = 0;
//         while (l <= r) {
//             int mid = (l + r) / 2;
//             ll sq = (ll) mid * mid;
//             if (sq > n) {
//                 r = mid - 1;
//             } else if (sq < n) {
//                 l = mid + 1;
//                 res = mid;
//             } else {
//                 return mid;
//             }
//         }

//         return res;
//     }
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<ll> maxHeap(gifts.begin(), gifts.end());

        ll sum = 0;
        for (auto n : gifts) {
            sum += n;
        }

        while(k--) {
            ll top = maxHeap.top();
            maxHeap.pop();
            sum -= top;
            top = (int) floor(sqrt(top));
            sum += top;
            maxHeap.push(top);
        }
        
        return sum;
    }
};