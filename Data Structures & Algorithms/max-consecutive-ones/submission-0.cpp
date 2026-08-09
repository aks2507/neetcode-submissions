class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0, count = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (i - 1 >= 0 && (nums[i] == 1 && nums[i - 1] == 1)) {
                count++;
            } else if (nums[i] != 1) {
                count = 0;
            } else if ((i - 1 >= 0 && (nums[i] == 1 && nums[i - 1] != 1)) || (i == 0 && nums[i] == 1)) {
                count = 1;
            }
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};