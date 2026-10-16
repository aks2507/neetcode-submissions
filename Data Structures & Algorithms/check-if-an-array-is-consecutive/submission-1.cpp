class Solution {
public:
    bool isConsecutive(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // for (int i = 1; i < nums.size(); i++) {
        //     if (nums[i] - nums[i - 1] != 1) {
        //         return false;
        //     }
        // }

        // return true;
        int n = nums.size();
        if (n == 1) return true;

        unordered_set<int> st(nums.begin(), nums.end());

        if (st.size() != n) {
            return false;
        }

        for (int i = 0; i < n; i++) {
            if (!(st.count(nums[i] + 1) || st.count(nums[i] - 1))) {
                return false;
            }
        }

        return true;
    }
};
