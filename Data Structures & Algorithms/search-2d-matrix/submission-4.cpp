class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Find row
        int row_l = 0, row_r = matrix.size() - 1;
        int target_row = 0;
        while (row_l <= row_r) {
            int row_mid = (row_l + row_r) / 2;
            if (target < matrix[row_mid][0]) {
                row_r = row_mid - 1;
            } else if (target > matrix[row_mid][matrix[0].size() - 1]) {
                row_l = row_mid + 1;
            } else {
                target_row = row_mid;
                break;
            }
        }

        // Find exact number
        int l = 0, r = matrix[0].size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (target < matrix[target_row][mid]) {
                r = mid - 1;
            } else if (target > matrix[target_row][mid]) {
                l = mid + 1;
            } else {
                return true;
            }
        }

        return false;
    }
};
