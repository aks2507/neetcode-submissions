class Solution {
private:
    vector<vector<int>> directionVectors = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    bool isValidCell(int row, int col, vector<vector<int>>& grid) {
        return row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size();
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> levels;
        int fresh = 0;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 2) {
                    levels.push({i, j});
                } else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int minutes = 0;
        while(!levels.empty() && fresh > 0) {
            minutes += 1;
            int len = levels.size();
            for (int i = 0; i < len; i++) {
                int row = levels.front().first;
                int col = levels.front().second;
                levels.pop();

                for(auto& vec: directionVectors) {
                    int nextRow = row + vec[0];
                    int nextCol = col + vec[1];

                    if(isValidCell(nextRow, nextCol, grid) && grid[nextRow][nextCol] == 1) {
                        fresh--;
                        grid[nextRow][nextCol] = 2;
                        levels.push({nextRow, nextCol});
                    }
                }
            }
        }

        return (fresh > 0) ? -1 : minutes;
    }
};
