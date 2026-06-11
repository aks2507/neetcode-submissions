class Solution {
private:
    vector<string> res;

    void rec(int n, int open, int close, string& s) {
        if (open == close && close == n) {
            res.push_back(s);
            return;
        }

        if (open < n) {
            s = s + '(';
            rec(n, open + 1, close, s);
            s.pop_back();
        }

        if (close < open) {
            s = s + ')';
            rec(n, open, close + 1, s);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string s = "";
        rec(n, 0, 0, s);
        return res;
    }
};
