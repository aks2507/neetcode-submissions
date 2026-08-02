class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size(), k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i < j && nums[i] == nums[j]) {
                    k++;
                }
            }
        }

        return k;
    }
};