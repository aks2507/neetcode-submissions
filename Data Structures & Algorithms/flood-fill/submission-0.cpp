class Solution {
    int rows = 0, cols = 0;
    bool isValidCell(int row, int col) {
        return row >= 0 && row < rows && col >= 0 && col < cols;
    }

    vector<vector<int>> dir = {
        {0, 1},
        {1, 0},
        {-1, 0},
        {0, -1}
    };

    void dfs(vector<vector<int>>& image, int row, int col, int original, int color) {
        if (!isValidCell(row, col) || image[row][col] != original) {
            return;
        }

        image[row][col] = color;
        for (auto& v : dir) {
            dfs(image, row + v[0], col + v[1], original, color);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        rows = image.size();
        cols = image[0].size();

        int original = image[sr][sc];
        if (original == color) {
            return image;
        }

        dfs(image, sr, sc, original, color);

        return image;
    }
};