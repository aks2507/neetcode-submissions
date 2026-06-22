class Solution {
private:
    vector<vector<int>> directionVectors = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };
    bool isValidCell(int row, int col, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        return row >= 0 && row < n && col >= 0 && col < m;
    }

    void dfs(int row, int col, vector<vector<char>>& grid) {
        grid[row][col] = -1;

        for(auto& vec: directionVectors) {
            int nextRow = row + vec[0];
            int nextCol = col + vec[1];
            if (isValidCell(nextRow, nextCol, grid) && grid[nextRow][nextCol] == '1') {
                dfs(nextRow, nextCol, grid);
            }
        }

        return;
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                if (grid[row][col] == '1') {
                    dfs(row, col, grid);
                    islands++;
                }
            }
        }

        return islands;
    }
};
