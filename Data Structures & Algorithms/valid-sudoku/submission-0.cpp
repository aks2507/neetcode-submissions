class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int, unordered_set<char>> rows;
        map<int, unordered_set<char>> cols;
        map<int, unordered_set<char>> boxes;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if(rows[i].find(board[i][j]) != rows[i].end()) {
                    // cout << "return 1-if false at i = " << i << " and j = " << j << endl;
                    return false;
                } else {
                    rows[i].insert(board[i][j]);
                }
                
                if (cols[j].find(board[i][j]) != cols[j].end()) {
                    // cout << "return 2-if false at i = " << i << " and j = " << j << endl;
                    return false;
                } else {
                    cols[j].insert(board[i][j]);
                }
                if (boxes[(i / 3) * 3 + j / 3].find(board[i][j]) != boxes[(i / 3) * 3 + j / 3].end()) {
                    // cout << "i: " << i << " and j: " << j << ", Box number: " << (i / 3) * 3 + j / 3 << endl;
                    // cout << "return 3-if false at i = " << i << " and j = " << j << endl;
                    return false;
                } else {
                    boxes[(i / 3) * 3 + j / 3].insert(board[i][j]);
                }
                
            }
        }

        return true;
    }
};
