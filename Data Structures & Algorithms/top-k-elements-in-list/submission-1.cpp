class Solution {
public:
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     unordered_map<int, int> fmp;
    //     for(int i = 0; i < nums.size(); i++) {
    //         fmp[nums[i]]++;
    //     }

    //     vector<vector<int>> count(nums.size());

    //     for(const auto& i : fmp) {
    //         count[i.second - 1].push_back(i.first);
    //     }

    //     // for(int i = 0; i < count.size(); i++) {
    //     //     cout<< i + 1 << " : ";
    //     //     if (!count[i].empty()) {
    //     //         for(int j = 0; j < count[i].size(); j++) {
    //     //             cout << count[i][j] << ", ";
    //     //         } 
    //     //     }
    //     //     cout << endl;
    //     // }

    //     vector<int> res;
    //     for(int i = count.size() - 1; i >= 0; i--) {
    //         if(count[i].size() == 0) {
    //             continue;
    //         }
    //         if (k <= 0) {
    //             break;
    //         }
    //         if (!count[i].empty()) {
    //             for(int j = 0; j < count[i].size(); j++) {
    //                 if(k > 0) {
    //                     res.push_back(count[i][j]);
    //                     k--;
    //                 } else {
    //                     break;
    //                 }
    //             }
    //         }
    //     }

    //     return res;
    // }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Calculate frequency of each element
        unordered_map<int, int> fmp;
        for(int i = 0; i < nums.size(); i++) {
            fmp[nums[i]]++;
        }

        // Create vector of each possible freqency - 1 to n and add corresponding elements from the frequency map
        vector<vector<int>> freq(nums.size());
        for(auto& p: fmp) {
            freq[p.second - 1].push_back(p.first);
        }

        // Starting from the last idx of the freq bucket, start pushing elements into the result array and keep decreasing k. Once k < 0, stop and return the array
        vector<int> res;
        for(int i = nums.size() - 1; i >= 0; i--) {
            if (freq[i].size() == 0) {
                continue;
            }
            
            if (k <= 0) {
                break;
            }

            for(int j = 0; j < freq[i].size(); j++) {
                res.push_back(freq[i][j]);
                k--;
            }
        }

        return res;

    }
};
