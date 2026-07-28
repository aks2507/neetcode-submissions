class Solution {
private:
    vector<vector<int>> dirs = {
        {0, 1}, 
        {1, 0},
        {-1, 0},
        {0, -1}
    };

    bool isValidCell(int row, int col, vector<vector<char>>& grid) {
        return row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size();
    }
    
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (row >= rows || col >= cols) {
            return;
        }

        visited[row][col] = true;
        for (auto& vec : dirs) {
            int nextRow = row + vec[0];
            int nextCol = col + vec[1];
            
            if(isValidCell(nextRow, nextCol, grid) && grid[nextRow][nextCol] == '1' && !visited[nextRow][nextCol]) {
                dfs(grid, visited, nextRow, nextCol);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == '1' && !visited[row][col]) {
                    count++;
                    dfs(grid, visited, row, col);
                }
            }
        }

        return count;
    }
};
