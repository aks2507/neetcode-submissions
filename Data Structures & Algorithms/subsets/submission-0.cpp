class Solution {
public:
    void subsetsRec(int i, vector<int>& nums, vector<int>& subset, vector<vector<int>>& subsets) {
        int n = nums.size();
        if(i >= n) {
            subsets.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        subsetsRec(i + 1, nums, subset, subsets);
        subset.pop_back();
        subsetsRec(i + 1, nums, subset, subsets);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> subset;
        int i = 0;
        subsetsRec(i, nums, subset, subsets);
        return subsets;
    }
};
