class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // O(nlogn solution)
    //     if (nums.size() == 0) {
    //         return 0;
    //     } else if (nums.size() == 1) {
    //         return 1;
    //     }
    //     sort(nums.begin(), nums.end());

    //     int res = 1;
    //     int max_till_now = 1;
    //     for(int i = 0; i < nums.size() - 1; i++) {
    //         if (nums[i + 1] - nums[i] == 1) {
    //             cout << "consecutive! numbers now: " << nums[i] << " & " << nums[i + 1] << endl;
    //             max_till_now += 1;
    //             res = max(max_till_now, res);
    //             cout << "Max till now: " << max_till_now << " AND result till now: " << res << endl;
    //         } else if (nums[i + 1] - nums[i] == 0) {
    //             continue;
    //         } else {
    //             cout << "Not consecutive!" << endl;
    //             max_till_now = 1;
    //         }
    //     }

    //     return res;
    // }


    // O(n) Solution
        unordered_set<int> s(nums.begin(), nums.end());

        int res = 0;

        for(int n : s) {
            if (s.find(n - 1) == s.end()) {
                int max_till_now = 1;
                while(s.find(n + max_till_now) != s.end()) {
                    max_till_now++;
                }
                res = max(max_till_now, res);
            }
        }

        return res;
    }
};
