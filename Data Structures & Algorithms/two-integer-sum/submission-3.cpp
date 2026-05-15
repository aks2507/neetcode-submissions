class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> idx;

        vector<int> res;

        for(int i= 0; i < nums.size(); i++) {
            if (idx.find(target - nums[i]) != idx.end()) {
                if (i > idx[target - nums[i]]) {
                    res.push_back(idx[target - nums[i]]);
                    res.push_back(i);
                } else {
                    res.push_back(i);
                    res.push_back(idx[target - nums[i]]);
                }
                break;
            } else {
                idx[nums[i]] = i;
            }
        }

        return res;
    }
};
