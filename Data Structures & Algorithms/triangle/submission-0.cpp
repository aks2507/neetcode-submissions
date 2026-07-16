class Solution {
private:
    int dfs(int row, int col, vector<vector<int>>& triangle, vector<vector<int>>& mem) {
        if (row >= triangle.size()) {
            return 0;
        }

        if (mem[row][col] != INT_MAX) {
            return mem[row][col];
        }

        mem[row][col] = triangle[row][col] + min(dfs(row + 1, col, triangle, mem), dfs(row + 1, col + 1, triangle, mem));

        return mem[row][col];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> mem(n, vector<int>(0));
        for (int i = 0; i < n; i++) {
            mem[i].resize(triangle[i].size(), INT_MAX);
        }
        
        return dfs(0, 0, triangle, mem);
    }
};