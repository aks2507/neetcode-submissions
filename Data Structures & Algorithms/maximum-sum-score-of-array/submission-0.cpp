typedef long long ll;
class Solution {
public:
    long long maximumSumScore(vector<int>& nums) {
        int n = nums.size();
        vector<ll> pre(n);
        vector<ll> suf(n);

        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + (ll) nums[i];
        }

        suf[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = suf[i + 1] + (ll) nums[i];
        }
        
        ll maxScore = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            maxScore = max(maxScore, max(pre[i], suf[i]));
        }

        return maxScore;
    }
};
