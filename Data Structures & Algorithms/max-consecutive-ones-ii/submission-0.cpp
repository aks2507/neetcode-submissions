class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0, right = 0, n = nums.size();
        int numZeros = 0, maxSize = INT_MIN;
        while (right < n) {
            if (nums[right] == 0) {
                numZeros++;
            }

            while (numZeros == 2) {
                if (nums[left] == 0) {
                    numZeros--;
                }
                left++;
            }

            maxSize = max(maxSize, right - left + 1);
            right++;
        }

        return maxSize;
    }
};
