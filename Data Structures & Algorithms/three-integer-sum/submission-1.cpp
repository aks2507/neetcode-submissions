class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> dup;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            int target = (-1) * nums[i];
            int l = 0, r = n - 1;
            cout << "For 3rd number: " << nums[i] << endl;
            while(l < r) {
                if (l == i) {
                    cout << "Left same as target: " << nums[l] << endl;
                    l++;
                    continue;
                }

                if(r == i) {
                    cout << "Right same as target: " << nums[r] << endl;
                    r--;
                    continue;
                }

                if (nums[l] + nums[r] > target) {
                    cout << "Grater than 0, moving rp to left. Left: " << l << " AND Right: " << r << endl; 
                    r--;
                } else if (nums[l] + nums[r] < target) {
                    cout << "less than 0, moving lp to right. Left: " << l << " AND Right: " << r << endl;
                    l++;
                } else {
                    cout << "Equality! At l: " << nums[l] << " AND r: " << nums[r] << endl;
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[l]);
                    tmp.push_back(nums[r]);
                    sort(tmp.begin(), tmp.end());
                    if (dup.find(tmp) == dup.end()) {
                        dup.insert(tmp);
                        res.push_back(tmp);
                    }
                    l++;
                    r--;
                }
            }
        }

        return res;
    }
};
