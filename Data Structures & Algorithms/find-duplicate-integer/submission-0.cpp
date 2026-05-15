class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res = -1;
        for (int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1;

            if (nums[idx] > 0) {
                nums[idx] = nums[idx] * -1;
            } else {
                res = idx + 1;
            }
        }
        return res;
    }
};
