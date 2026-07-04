class Solution {
private:
    vector<vector<int>> directions = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
    };

    bool isValidCell(int row, int col, vector<vector<char>>& board) {
        if (row >= 0 && row < board.size() && col >= 0 && col < board[0].size()) {
            return true;
        }

        return false;
    }

    bool dfs(int row, int col, vector<vector<char>>& board, vector<vector<bool>>& visited, string word, int idx) {
        if (idx == word.length()) {
            return true; 
        }
        
        if(!isValidCell(row, col, board)) {
            return false;
        }

        if (visited[row][col]) {
            return false;
        }

        if (board[row][col] != word[idx]) {
            return false;
        }


        visited[row][col] = true;

        for (auto& vec: directions) {
            int nextRow = row + vec[0];
            int nextCol = col + vec[1];
            if (dfs(nextRow, nextCol, board, visited, word, idx + 1)) {
                return true;
            }
        }
        visited[row][col] = false;

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.length() == 0) {
            return false;
        }
        int rows = board.size(), cols = board[0].size(); 
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {
                if(dfs(row, col, board, visited, word, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};
