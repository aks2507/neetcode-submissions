class Solution {
private:
    vector<vector<int>> directionVectors = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    bool isValidCell(int row, int col, vector<vector<int>>& heights) {
        return row >= 0 && col >= 0 && row < heights.size() && col < heights[0].size();
    }

    void dfs(int row, int col, vector<vector<bool>>& ocean, vector<vector<int>>& heights) {
        ocean[row][col] = true;
        for(auto& vec: directionVectors) {
            int nextRow = row + vec[0];
            int nextCol = col + vec[1];

            if(isValidCell(nextRow, nextCol, heights) && !ocean[nextRow][nextCol] && heights[nextRow][nextCol] >= heights[row][col]) {
                dfs(nextRow, nextCol, ocean, heights);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> res;
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        for(int i = 0; i < cols; i++) {
            dfs(0, i, pacific, heights);
            dfs(rows - 1, i, atlantic, heights);
        }

        for(int i = 0; i < rows; i++) {
            dfs(i, 0, pacific, heights);
            dfs(i, cols - 1, atlantic, heights);
        }

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};
