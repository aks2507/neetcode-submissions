class Solution {
public:
    // vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //     unordered_map<string, vector<string>> res_map;
    //     vector<vector<string>> res;

    //     for(const auto& s : strs) {
    //         vector<int> freq(26, 0);
    //         for (char c : s) {
    //             freq[c - 'a']++;
    //         }

    //         string key = to_string(freq[0]);
    //         for(int j = 1; j < 26; j++) {
    //             key += ',' + to_string(freq[j]);
    //         }

    //         res_map[key].push_back(s);
    //     }

    //     for(const auto& pair : res_map) {
    //         res.push_back(pair.second);
    //     }

    //     return res;
    // }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res_map;
        vector<vector<string>> res;

        for (int i = 0; i < strs.size(); i++) {
            // Build a frequency array for every string
            vector<int> freq(26, 0);
            for (int j = 0; j < strs[i].size(); j++) {
                freq[strs[i][j] - 'a']++;
            }

            // Build a string with frequencies separated by a delimiter, say "," and add to the hash map
            string key = "";
            for(int j = 0; j < 26; j++) {
                key += to_string(freq[j]) + ",";
            }

            res_map[key].push_back(strs[i]);
        }

        // Iterate through the map and add grouped strings in the result array
        for(auto& element: res_map) {
            res.push_back(element.second);
        }

        return res;
    }
};
