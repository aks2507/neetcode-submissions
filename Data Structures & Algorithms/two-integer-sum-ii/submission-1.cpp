class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while(l < r) {
            if (numbers[l] + numbers[r] > target) {
                cout << "Sum of numbers: " << numbers[l] << " AND " << numbers[r] << " is greater than target: " << target << endl;
                r--;
            } else if (numbers[l] + numbers[r] < target) {
                l++;
            } else {
                vector<int> res;
                res.push_back(l + 1);
                res.push_back(r + 1);
                return res;
            }
        }

        return vector<int>(0);
    }
};
