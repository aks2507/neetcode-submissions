class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0, sumL = 0, i = 0;

        for (i = 0; i < nums.size(); i++) {
            total += nums[i];
        }

        for (i = 0; i < nums.size(); i++) {
            int sumR = total - sumL - nums[i];

            if (sumL == sumR) {
                return i;
            }

            sumL += nums[i];
        }

        return -1;
    }
};