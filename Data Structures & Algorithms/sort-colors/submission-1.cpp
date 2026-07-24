class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> arr(3, 0);

        for (int i = 0; i < nums.size(); i++) {
            arr[nums[i]]++;
        }

        int k = 0;
        for (int i = 0; i < 3; i++) {
            while(arr[i]--) {
                nums[k++] = i;
            }
        }
    }
};