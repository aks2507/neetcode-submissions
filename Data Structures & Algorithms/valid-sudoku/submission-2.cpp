class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int, unordered_set<char>> rows, cols;
        map<pair<int, int>, unordered_set<char>> boxes;

        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (board[row][col] == '.') {
                    continue;
                }
                // Check logic
                pair<int, int> p = {row / 3, col / 3};
                if (rows[row].count(board[row][col]) || cols[col].count(board[row][col]) || boxes[p].count(board[row][col])) {
                    return false;
                }
                rows[row].insert(board[row][col]);
                cols[col].insert(board[row][col]);
                boxes[p].insert(board[row][col]);
            }
        }
        return true;
    }
};
