class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        if (paths.size() == 1) {
            return paths[0][1];
        }

        unordered_map<string, string> mp;

        for (const auto& vec : paths) {
            mp[vec[0]] = vec[1];
        }

        for (const auto& [s1, s2] : mp) {
            if (!mp.count(s2)) {
                return s2;
            }
        }

        return "";
    }
};
