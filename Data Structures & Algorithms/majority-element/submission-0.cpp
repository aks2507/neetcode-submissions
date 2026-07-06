class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> f;

        for(int i = 0; i < nums.size(); i++) {
            f[nums[i]]++;
        }

        int maxF = INT_MIN;
        int maj = INT_MIN;
        for(auto& [key, val] : f) {
            if (val > maxF) {
                maxF = val;
                maj = key;
            }
        }

        return maj;
    }
};