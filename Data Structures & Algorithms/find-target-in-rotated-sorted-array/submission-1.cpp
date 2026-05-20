class Solution {
public:
    int binSearch(vector<int>& nums, int target, int l, int r) {
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] > target) {
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int idx = 0;
        while(l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        int pivot = l;
        int res = binSearch(nums, target, 0, pivot - 1);
        if (res == -1) {
            res = binSearch(nums, target, pivot, nums.size() - 1);
        }

        return res;
    }
};
