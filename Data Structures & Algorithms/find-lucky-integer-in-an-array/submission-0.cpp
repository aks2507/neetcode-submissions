class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;

        for (int val : arr) {
            mp[val]++;
        }

        int res = -1;
        for (auto& [k, v] : mp) {
            if (k == v) {
                res = max(res, k);
            }
        }

        return res;
    }
};