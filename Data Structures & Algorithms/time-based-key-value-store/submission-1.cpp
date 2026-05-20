class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> kvstore;
    TimeMap() {
    
    }
    
    void set(string key, string value, int timestamp) {
        pair<string, int> val = {value, timestamp};
        kvstore[key].push_back(val);
    }
    
    string get(string key, int timestamp) {
        if (kvstore.find(key) == kvstore.end()) {
            return "";
        }
        vector<pair<string, int>> vals = kvstore[key];
        int l = 0, r = vals.size() - 1;
        string res = "";

        while (l <= r) {
            int mid = (l + r) / 2;

            if (timestamp >= vals[mid].second) {
                res = vals[mid].first;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return res;
    }
};
