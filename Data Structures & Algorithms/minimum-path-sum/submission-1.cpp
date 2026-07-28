class Solution {
private:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& mem, int i, int j, int m, int n) {
        if (i == m - 1 && j == n - 1) {
            mem[i][j] = grid[i][j];
            return grid[i][j];
        }

        if (i >= m || j >= n) {
            return INT_MAX;
        }

        if (mem[i][j] != INT_MAX) {
            return mem[i][j];
        }

        mem[i][j] = grid[i][j] + min(dfs(grid, mem, i + 1, j, m, n), dfs(grid, mem, i, j + 1, m, n));
        
        return mem[i][j];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> mem(m, vector<int>(n, INT_MAX));

        return dfs(grid, mem, 0, 0, m, n);
    }
};