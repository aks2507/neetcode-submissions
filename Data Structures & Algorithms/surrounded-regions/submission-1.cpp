class Solution {
private:
    vector<vector<int>> directionVectors = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    bool isValidCell(int row, int col, vector<vector<char>>& board) {
        return row >= 0 && col >= 0 && row < board.size() && col < board[0].size();
    }

    bool isBorderCell(int row, int col, vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        return row == 0 || col == 0 || row == rows - 1 || col == cols - 1;
    }

    void dfs(vector<vector<char>>& board, int row, int col, vector<vector<bool>>& borderConnect) {
        borderConnect[row][col] = true;
        for (auto& vec : directionVectors) {
            int nextRow = row + vec[0];
            int nextCol = col + vec[1];

            if (isValidCell(nextRow, nextCol, board) && !borderConnect[nextRow][nextCol] && board[nextRow][nextCol] == 'O') {
                dfs(board, nextRow, nextCol, borderConnect);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        
        vector<vector<bool>> borderConnect(rows, vector<bool>(cols, false));

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (isBorderCell(row, col, board) && board[row][col] == 'O') {
                    dfs(board, row, col, borderConnect);
                }
            }
        }

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (!borderConnect[row][col] && board[row][col] == 'O') {
                    board[row][col] = 'X';
                }
            }
        }
    }
};
