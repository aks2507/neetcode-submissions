class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();

        if (rows == cols) {
            for (int row = 0; row < rows; row++) {
                for (int col = 0; col < row; col++) {
                    swap(matrix[row][col], matrix[col][row]);
                }
            }

            return matrix;
        }

        vector<vector<int>> res(cols, vector<int>(rows));
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                res[col][row] = matrix[row][col];
            }
        }

        return res;
    }
};