class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int threshold = floor(n / 3);

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        } 
        vector<int> res;
        for (const auto& [k, v] : mp) {
            if (v > threshold) {
                res.push_back(k);
            }
        }

        return res;
    }
};