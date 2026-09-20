class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size(), repeated = -1;
        for (int i = 0; i < n; i++) {
            int idx = abs(nums[i]) - 1;

            if (nums[idx] > 0) {
                nums[idx] *= -1;
            } else {
                repeated = idx + 1;
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                res = {repeated, i + 1};
            }
        }

        return res;
    }
};