class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if (numRows == 1 || numRows >= n) {
            return s;
        }

        vector<string> rowWise(numRows);
        int row = 0, dir = 1;
        for (char& c : s) {
            rowWise[row] += c;
            row += dir;
            if (row == 0 || row == numRows - 1) {
                dir *= -1;
            }
        }

        string ans = "";
        for (string& st : rowWise) {
            ans += st;
        }

        return ans;
    }
};