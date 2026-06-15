class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }

        if(nums.size() == 1) {
            return 1;
        }
        
        // sort(nums.begin(), nums.end());

        // int maxsum = 1;
        // int sumtillnow = 1;
        // for(int i = 1; i < nums.size(); i++) {
        //     if(nums[i] - nums[i - 1] == 1) {
        //         sumtillnow++;
        //         maxsum = max(maxsum, sumtillnow);
        //     } else if (nums[i] == nums[i - 1]) {
        //         continue;
        //     } else {
        //         sumtillnow = 1;
        //     }
        // }

        // return maxsum;

        unordered_set<int> s;
        for(int n : nums) {
            s.insert(n);
        }

        int maxlen = 0;

        for(int n: s) {
            if(s.find(n - 1) == s.end()) {
                int lentillnow = 1;
                while(s.find(n + lentillnow) != s.end()) {
                    lentillnow++;
                }

                maxlen = max(maxlen, lentillnow);
            }
        }

        return maxlen;
    }
};
