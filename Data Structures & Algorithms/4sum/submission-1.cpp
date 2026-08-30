typedef long long ll;
class Solution {
private:
    vector<vector<int>> res;
    vector<int> vec;
    int n;
    void kSum(int start, int k, vector<int>& nums, ll target) {
        if (k == 2) {
            int l = start, r = n - 1;
            while (l < r) {
                ll sum = (ll)(nums[l] + nums[r]);
                if (sum == target) {
                    vec.push_back(nums[l]);
                    vec.push_back(nums[r]);
                    res.push_back(vec);
                    vec.pop_back();
                    vec.pop_back();
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                    while (l < r && nums[r] == nums[r + 1]) {
                        r--;
                    }
                } else if (sum < target) {
                    l++;
                } else {
                    r--;
                }
            }
        } else {
            for (int i = start; i < n - k + 1; i++) {
                if (i > start && nums[i] == nums[i - 1]) {
                    continue;
                }
                vec.push_back(nums[i]);
                kSum(i + 1, k - 1, nums, target - nums[i]);
                vec.pop_back();
            }   
        }

        return;
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        n = nums.size();
        if (n < 4) {
            return {};
        }
        sort(nums.begin(), nums.end());
        kSum(0, 4, nums, (ll) target);

        return res;
    }
};