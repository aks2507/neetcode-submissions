class Solution {
public:
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     unordered_map<int, int> idx;
        
    //     for(int i = 0; i < nums.size(); i++) {
    //         idx[nums[i]] = i;
    //     }

    //     vector<int> res;

    //     for(int i = 0; i < nums.size(); i++) {
    //         if(idx.find(target - nums[i]) != idx.end()) {
    //             int j = idx[target - nums[i]];
    //             if(i != j) {
    //                 if (i > j) {
    //                     res.push_back(j);
    //                     res.push_back(i);
    //                     break;
    //                 } else {
    //                     res.push_back(i);
    //                     res.push_back(j);
    //                     break;
    //                 }
    //             }
    //         }
    //     }

    //     return res;
    // }

    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int, int> idx;

        vector<int> res;

        for(int i= 0; i < n; i++) {
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
