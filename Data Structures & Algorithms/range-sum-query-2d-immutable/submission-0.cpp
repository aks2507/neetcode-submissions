class NumMatrix {
    vector<vector<int>> sum;
    int rows = 0, cols = 0;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();

        sum = vector<vector<int>>(rows, vector<int>(cols, 0));
        int prefix = 0;
        for (int col = 0; col < cols; col++) {
            prefix += matrix[0][col];
            sum[0][col] = prefix;
        }

        prefix = 0;
        for (int row = 0; row < rows; row++) {
            prefix += matrix[row][0];
            sum[row][0] = prefix;
        }

        for (int row = 1; row < rows; row++) {
            prefix = matrix[row][0];
            for (int col = 1; col < cols; col++) {
                prefix += matrix[row][col];
                sum[row][col] = prefix + sum[row - 1][col];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = sum[row2][col2];
        if (row1 > 0) {
            res -= sum[row1 - 1][col2];
        }
        if (col1 > 0) {
            res -= sum[row2][col1 - 1];
        }

        if (row1 > 0 && col1 > 0) {
            res += sum[row1 - 1][col1 - 1];
        }

        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */