class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) {
            return n;
        }
        
        int res = INT_MIN;
        unordered_set<int> st(nums.begin(), nums.end());

        for (int num: st) {
            if (num != INT_MIN && st.count(num - 1)) {
                continue;
            }
            int lengthTillNow = 0;

            while (st.count(num + lengthTillNow)) {
                lengthTillNow++;
            }

            res = max(res, lengthTillNow);
        }

        return res;
    }
};
