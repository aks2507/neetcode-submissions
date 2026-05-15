class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        } else if (nums.size() == 1) {
            return 1;
        }
        sort(nums.begin(), nums.end());

        int res = 1;
        int max_till_now = 1;
        for(int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] - nums[i] == 1) {
                cout << "consecutive! numbers now: " << nums[i] << " & " << nums[i + 1] << endl;
                max_till_now += 1;
                res = max(max_till_now, res);
                cout << "Max till now: " << max_till_now << " AND result till now: " << res << endl;
            } else if (nums[i + 1] - nums[i] == 0) {
                continue;
            } else {
                cout << "Not consecutive!" << endl;
                max_till_now = 1;
            }
        }

        return res;
    }
};
