class Solution {
public:
    int robDp(vector<int>& nums, vector<int>& rob, int i, int end) {
        if (i >= end) {
            return 0;
        }

        if (rob[i] != -1) {
            return rob[i];
        }
        rob[i] = max(nums[i] + robDp(nums, rob, i + 2, end), robDp(nums, rob, i + 1, end));
        return rob[i];
    }
    
    int rob(vector<int>& nums) {

        if (nums.size() == 1) return nums[0];
        vector<int> rob(nums.size(), -1);
        vector<int> rob2(nums.size(), -1);
        return max(robDp(nums, rob, 0, nums.size() - 1), robDp(nums, rob2, 1, nums.size()));
    }
};
