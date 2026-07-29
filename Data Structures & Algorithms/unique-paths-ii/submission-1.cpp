class Solution {
private:
    int dfs(int row, int col, vector<vector<int>>& obstacleGrid, vector<vector<int>>& mem) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (row >= m || col >= n || obstacleGrid[row][col] == 1) {
            return 0;
        }

        if (row == m - 1 && col == n - 1) {
            return 1;
        }

        if (mem[row][col] != 0) {
            return mem[row][col];
        }

        int res = 0;
        if (row < m - 1) {
            res += dfs(row + 1, col, obstacleGrid, mem);
        }

        if (col < n - 1) {
            res += dfs(row, col + 1, obstacleGrid, mem);
        }

        mem[row][col] = res;
        return res;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }

        vector<vector<int>> mem(m, vector<int>(n, 0));

        return dfs(0, 0, obstacleGrid, mem);
    }
};