class Solution {
    bool binSearch(vector<int>& vec, int l, int r, int target) {
        while (l <= r) {
            int mid = (l + r) / 2;
            if (vec[mid] == target) {
                return true;
            } else if (vec[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return false;
    }
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        for (int col = 0; col < cols; col++) {
            bool found = true;
            for (int row = 1; row < rows && found; row++) {
                found = binSearch(mat[row], 0, cols - 1, mat[0][col]);
            }

            if (found) {
                return mat[0][col];
            }
        }

        return -1;
    }
};
