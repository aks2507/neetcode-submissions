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
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> levels;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 0) {
                    levels.push({i, j});
                }
            }
        }

        int distance = 0;
        while(!levels.empty()) {
            int row = levels.front().first;
            int col = levels.front().second;
            levels.pop();

            for (auto& vec: directionVectors) {
                int nextRow = row + vec[0];
                int nextCol = col + vec[1];

                if (isValidCell(nextRow, nextCol, grid) && grid[nextRow][nextCol] == INT_MAX) {
                    grid[nextRow][nextCol] = grid[row][col] + 1;
                    levels.push({nextRow, nextCol});
                } else {
                    continue;
                }
            }
        }
    }
};
