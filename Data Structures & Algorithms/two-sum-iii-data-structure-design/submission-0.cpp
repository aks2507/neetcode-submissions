class TwoSum {
    unordered_map<int, vector<int>> mp;
    int i = 0;
public:
    TwoSum() {}
    void add(int number) {
        mp[number].push_back(i++);
    }
    bool find(int value) {
        for (auto& [num, indices] : mp) {
            if (mp.count(value - num) && (value - num != num || (value - num == num && mp[num].size() > 1))) {
                return true;
            }
        }
        return false;
    }
};
