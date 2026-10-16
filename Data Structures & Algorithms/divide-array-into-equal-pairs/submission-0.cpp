class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int n : nums) {
            mp[n]++;
        }

        for (auto& [k, v] : mp) {
            if (v % 2) return false;
        }

        return true;
    }
};