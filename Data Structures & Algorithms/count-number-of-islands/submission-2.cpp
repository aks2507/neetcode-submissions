class Solution {
    int rows =  0, cols = 0;
    vector<vector<int>> dir = {
        {0, 1},
        {1, 0},
        {-1, 0},
        {0, -1}
    };

    bool isValidCell(int row, int col) {
        return row >= 0 && row < rows && col >= 0 && col < cols;
    }

    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        visited[row][col] = true;

        for (auto& vec : dir) {
            int nextrow = row + vec[0];
            int nextcol = col + vec[1];

            if (isValidCell(nextrow, nextcol) && grid[nextrow][nextcol] == '1' && !visited[nextrow][nextcol]) {
                dfs(nextrow, nextcol, grid, visited);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int count = 0;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == '1' && !visited[row][col]) {
                    count++;
                    dfs(row, col, grid, visited);
                }
            }
        }

        return count;
    }
};
