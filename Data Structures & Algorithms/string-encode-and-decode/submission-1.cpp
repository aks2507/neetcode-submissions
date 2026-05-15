class Solution {
public:

    // string encode(vector<string>& strs) {
    //     string res = "";

    //     for (int i = 0; i < strs.size(); i++) {
    //         res += to_string(strs[i].size()) + "@" + strs[i];
    //     }

    //     cout << "Encoded: " << res << endl; 
    //     return res;
    // }

    // vector<string> decode(string s) {
    //     vector<string> res;

    //     int i = 0;
    //     while(i < s.size()) {
    //         string len = "";
    //         while(s[i] != '@') {
    //             len += s[i];
    //             i++;
    //         }

    //         cout << "Length received: " << len << endl;

    //         int l = stoi(len);
    //         string tmp = "";
    //         i++;
    //         while(l > 0) {
    //             tmp += s[i];
    //             l--;
    //             i++;
    //         }

    //         cout << "String received: " << tmp << endl;

    //         res.push_back(tmp);
    //     }

    //     return res;

    // }

    string encode(vector<string>& strs) {
        // length + delimiter special character + actual string

        string res = "";

        for (int i = 0; i < strs.size(); i++) {
            res += to_string(strs[i].size()) + '@' + strs[i];
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;

        int i = 0;
        while(i < s.size()) {
            // Get the length
            string len = "";
            while(s[i] != '@') {
                len += s[i];
                i++;
            }

            int size = stoi(len);
            // Based on the length get the string
            string str = "";
            i++;
            while(size > 0) {
                str += s[i];
                i++;
                size--;
            }

            res.push_back(str);
        }
        return res;
    }
};
