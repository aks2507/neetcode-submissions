class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        bool dip = false;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] < nums[i] && dip) {
                return false;
            } else if (!dip && nums[i + 1] < nums[i]) {
                dip = true;
            }
        }
        if (nums[n - 1] > nums[0] && dip) {
            return false;
        }
        
        return true;
    }
};