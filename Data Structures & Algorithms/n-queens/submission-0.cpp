class Solution {
private:
    vector<vector<string>> res;
    unordered_set<int> cols;
    unordered_set<int> posDiag;
    unordered_set<int> negDiag;
    void solveNQueensRec(int row, int n, vector<string>& board) {
        if (row == n) {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (cols.count(col) || posDiag.count(row + col) || negDiag.count(row - col)) {
                continue;
            }

            cols.insert(col);
            posDiag.insert(row + col);
            negDiag.insert(row - col);
            board[row][col] = 'Q';
            solveNQueensRec(row + 1, n, board);
            cols.erase(col);
            posDiag.erase(row + col);
            negDiag.erase(row - col);
            board[row][col] = '.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        solveNQueensRec(0, n, board);
        return res;
    }
};
