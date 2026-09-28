class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0, n = mat.size();

        for (int i = 0; i < n; i++) {
            sum += mat[i][i];
            sum += (i == n - i - 1) ? 0 : mat[i][n - i - 1];
        }

        return sum;
    }
};