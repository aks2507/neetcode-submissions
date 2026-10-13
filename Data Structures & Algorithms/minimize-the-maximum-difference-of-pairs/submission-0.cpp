class Solution {
    bool canMakePairs(vector<int>& nums, int p, int maxDiff) {
        int pairs = 0;

        for (int i = 0; i + 1 < nums.size();) {
            if (nums[i + 1] - nums[i] <= maxDiff) {
                pairs++;
                i += 2;
            } else {
                i++;
            }

            if (pairs == p) {
                return true;
            }
        }

        return false;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int l = 0, r = nums.back() - nums.front();

        while (l < r) {
            int mid = (l + r) / 2;

            if (canMakePairs(nums, p, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};