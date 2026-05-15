class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";

        for (int i = 0; i < strs.size(); i++) {
            res += to_string(strs[i].size()) + "@" + strs[i];
        }

        cout << "Encoded: " << res << endl; 
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;

        int i = 0;
        while(i < s.size()) {
            string len = "";
            while(s[i] != '@') {
                len += s[i];
                i++;
            }

            cout << "Length received: " << len << endl;

            int l = stoi(len);
            string tmp = "";
            i++;
            while(l > 0) {
                tmp += s[i];
                l--;
                i++;
            }

            cout << "String received: " << tmp << endl;

            res.push_back(tmp);
        }

        return res;

    }
};
