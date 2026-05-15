class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        // set<vector<int>> dup;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int l = i + 1, r = n - 1;
            while(l < r) {
                int s = nums[l] + nums[r] + nums[i];
                if (s > 0) {
                    r--;
                } else if (s < 0) {
                    l++;
                } else {
                    vector<int> tmp;
                    tmp.push_back(nums[l]);
                    tmp.push_back(nums[r]);
                    tmp.push_back(nums[i]);
                    sort(tmp.begin(), tmp.end());
                    res.push_back(tmp);
                    l++;
                    r--;
                    while(l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                }
            }
        }

        return res;
    }
};
