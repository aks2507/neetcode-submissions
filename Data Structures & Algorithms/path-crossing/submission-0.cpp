class Solution {
    unordered_map<char, vector<int>> mp = {
        {'N', {1, 0}},
        {'E', {0, 1}},
        {'W', {0, -1}},
        {'S', {-1, 0}}
    };

    string encode(vector<int>& v) {
        string res = "";
        res += to_string(v[0]) + ',' + to_string(v[1]);

        return res;
    }
public:
    bool isPathCrossing(string path) {
        set<string> st;

        st.insert("0,0");
        vector<int> point = {0, 0};
        for (char c : path) {
            point[0] += mp[c][0];
            point[1] += mp[c][1];

            string s = encode(point);
            if (st.count(s)) {
                return true;
            }

            st.insert(s);
        }

        return false;
    }
};