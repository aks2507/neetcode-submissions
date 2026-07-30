class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (auto n : nums) {
            mp[n]++;
        }

        int max = -1;
        for (const auto& [k, v] : mp) {
            if (k >= max && v == 1) {
                max = k;
            }
        }

        return max;
    }
};
