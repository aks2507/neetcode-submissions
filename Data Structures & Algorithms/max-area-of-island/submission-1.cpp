class Solution {
private:
    vector<vector<int>> directionVectors = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };
    bool isValidCell(int row, int col, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        return row >= 0 && row < n && col >= 0 && col < m;
    }

    void dfs(int& islandArea, int row, int col, vector<vector<int>>& grid) {
        grid[row][col] = -1;

        for(auto& vec: directionVectors) {
            int nextRow = row + vec[0];
            int nextCol = col + vec[1];
            if (isValidCell(nextRow, nextCol, grid) && grid[nextRow][nextCol] == 1) {
                islandArea++;
                dfs(islandArea, nextRow, nextCol, grid);
            }
        }

        return;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxAreaIsland = INT_MIN;
        int n = grid.size();
        int m = grid[0].size();

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                if (grid[row][col] == 1) {
                    int islandArea = 1;
                    dfs(islandArea, row, col, grid);
                    maxAreaIsland = max(maxAreaIsland, islandArea);
                }
            }
        }

        return maxAreaIsland == INT_MIN ? 0 : maxAreaIsland;
    }
};
