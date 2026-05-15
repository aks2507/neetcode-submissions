class Solution {
public:
    // bool isAnagram(string s, string t) {
    //     if(s.size() != t.size()) {
    //         return false;
    //     }
    //     unordered_map<char, int> smp, tmp;

    //     for(int i = 0; i < s.size(); i++) {
    //         smp[s[i]]++;
    //         tmp[t[i]]++;
    //     }

    //     if (smp == tmp) {
    //         return true;
    //     }
    //     return false;
    // }

    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> smap, tmap;

        for (int i = 0; i < s.size(); i++) {
            smap[s[i]]++;
            tmap[t[i]]++;
        }

        return smap == tmap;
    }
};
