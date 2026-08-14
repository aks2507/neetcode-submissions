class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if (nums.size() == 1) {
            return true;
        }
        
        bool inc = false;
        int n = nums.size();
        if (nums[0] <= nums[n - 1]) {
            inc = true;
        }

        for (int i = 0; i < n - 1; i++) {
            if ((inc && nums[i] > nums[i + 1]) || (!inc && nums[i] < nums[i + 1])) {
                return false;
            }
        }

        return true;
    }
};