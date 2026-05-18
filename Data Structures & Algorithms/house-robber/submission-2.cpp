class Solution {
public:
    int robDp(vector<int>& nums, vector<int>& rob, int i) {
        if (i >= nums.size()) {
            return 0;
        }

        if (rob[i] != -1) {
            return rob[i];
        }
        rob[i] = max(nums[i] + robDp(nums, rob, i + 2), robDp(nums, rob, i + 1));
        return rob[i];
    }
    
    int rob(vector<int>& nums) {
        vector<int> rob(nums.size(), -1);
        return robDp(nums, rob, 0);
    }
};
