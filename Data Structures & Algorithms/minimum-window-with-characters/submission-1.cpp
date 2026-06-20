class Solution {
public:
    string minWindow(string s, string t) {
        if(t == "") {
            return "";
        }

        unordered_map<char, int> countT;
        for(auto& c: t) {
            if(!countT.count(c)) {
                countT[c] = 1;
            } else {
                countT[c]++;
            }
        }
        pair<int, int> bestWindow;
        int have = 0, need = countT.size();
        int res = INT_MAX;

        unordered_map<char, int> countWin;
        int l = 0;
        for(int r = 0; r < s.length(); r++) {
            char c = s[r];
            countWin.count(c) ? countWin[c]++ : countWin[c] = 1;
            if (countT.count(c) && countWin[c] == countT[c]) {
                have++;
            }

            while(have == need) {
                if ((r - l + 1) < res) {
                    res = r - l + 1;
                    bestWindow = {l, r};
                }
                countWin[s[l]]--;

                if (countT.count(s[l]) && countWin[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        return res == INT_MAX ? "":s.substr(bestWindow.first, res);
    }
};
