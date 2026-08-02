class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size(), k = 0;
        unordered_map<int, int> count;

        for (auto num : nums) {
            k += count[num];
            count[num]++;
        }

        return k;
    }
};