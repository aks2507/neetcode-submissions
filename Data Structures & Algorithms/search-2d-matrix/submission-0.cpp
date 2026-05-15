class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int row_l = 0, row_r = rows - 1;
        int col_l = 0, col_r = cols - 1; 
        int target_row = 0;
        while(row_l <= row_r) {
            int row_mid = (row_l + row_r) / 2;
            
            if (matrix[row_mid][0] > target) {
                row_r = row_mid - 1;
            } else if (matrix[row_mid][cols - 1] < target) {
                row_l = row_mid + 1;
            } else {
                cout << "The row to check is: " << row_mid << endl;
                target_row = row_mid;
                break;
            }
        }

        while (col_l <= col_r) {
            int col_mid = (col_l + col_r) / 2;

            if (matrix[target_row][col_mid] > target) {
                col_r = col_mid - 1;
            } else if (matrix[target_row][col_mid] < target) {
                col_l = col_mid + 1;
            } else {
                return true;
            }
        }

        return false;
    }
};
