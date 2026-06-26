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

    void dfs(int row, int col, vector<vector<bool>>& borderConnection, vector<vector<char>>& board) {
        borderConnection[row][col] = true;

        for(auto& vec: directionVectors) {
            int nextRow = row + vec[0];
            int nextCol = col + vec[1];

            if (isValidCell(nextRow, nextCol, board) && !borderConnection[nextRow][nextCol] && board[nextRow][nextCol] == 'O') {
                dfs(nextRow, nextCol, borderConnection, board);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> borderConnection(rows, vector<bool>(cols, false));

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if ((i == 0 || j == 0 || i == rows - 1 || j == cols - 1) && board[i][j] == 'O') {
                    dfs(i, j, borderConnection, board);
                }
            }
        }

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(!borderConnection[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
