#include<string>
class Solution {
public:
    string create_freq_string(string s) {
        vector<int> mpfs1(26, 0);
        for (char c : s) {
            mpfs1[c - 'a']++;
        }
        
        string fs1 = to_string(mpfs1[0]);
        for (int i = 1; i < 26; i++) {
            fs1 += "," + to_string(mpfs1[i]);
        }

        return fs1;
    }
    
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        string fs1 = create_freq_string(s1);
        
        int l = 0;
        while(l + s1.size() <= s2.size()) {
            string subs2 = s2.substr(l, s1.size());
            // cout << "Comparing s1 = " << s1 << " with substring of s2 = " << subs2 << endl;
            if (fs1 == create_freq_string(subs2)) {
                // cout << "Frequency string of s1 : " << fs1 << endl;
                // cout << "Freque string of subs2 : " << create_freq_string(subs2) << endl;
                // cout << "Equality!" << endl;
                return true;
            }
            l++;
        }

        return false;
    }
};
