class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int i = 0, j = 1;

        while (i < n && j <= n) {
            while (i < n && j > nums[i]) {
                i++;
            }

            if (j == n - i) {
                return j;
            }
            j++;
        }

        return -1;
    }
};