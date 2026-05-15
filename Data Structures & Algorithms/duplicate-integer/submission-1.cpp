class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // int n = nums.size();

        // unordered_set<int> numset;
        // for(int i = 0; i < nums.size(); i++) {
        //     if(numset.find(nums[i]) != numset.end()) {
        //         return true;
        //     } else {
        //         numset.insert(nums[i]);
        //     }
        // }

        // return false;

        int n = nums.size();

        unordered_set<int> elements;
        for (int i = 0; i < n; i++) {
            if (elements.find(nums[i]) == elements.end()) {
                elements.insert(nums[i]);
            } else {
                return true;
            }
        }

        return false;
    }
};