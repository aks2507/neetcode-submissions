class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        // vector<int> p(n);
        // vector<int> s(n);
        int pre = 1;
        for(int i = 0; i < n; i++) {
            res[i] = pre;
            pre *= nums[i];
        }

        int suf = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] = res[i] * suf;
            suf *= nums[i];
        }

        // for (int i = 0; i < n; i++) {
        //     res[i] = p[i] * s[i];
        // }

        return res;
    }
};
