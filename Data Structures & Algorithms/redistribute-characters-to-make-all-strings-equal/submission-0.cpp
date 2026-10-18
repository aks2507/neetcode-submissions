class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> mp;

        for (auto& word : words) {
            for (char& c : word) {
                mp[c]++;
            }
        }

        int n = words.size();
        for (const auto& [c, f] : mp) {
            if (f % n != 0) {
                return false;
            }
        }

        return true;
    }
};