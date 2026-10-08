class Solution {
    int rows = 0, cols = 0;
    bool isValidCell(int row, int col) {
        return row >= 0&& row < rows && col >= 0 && col < cols; 
    }

    vector<vector<int>> dir = {
        {0, 1},
        {1, 0},
        {-1, 0},
        {0, -1}
    };
    int perimeter = 0;
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        // vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 1) {
                    for (auto& v : dir) {
                        int nextRow = row + v[0];
                        int nextCol = col + v[1];

                        if (!isValidCell(nextRow, nextCol) || grid[nextRow][nextCol] == 0) {
                            perimeter++;
                        }
                    }
                }
            }
        }

        return perimeter;
    }
};