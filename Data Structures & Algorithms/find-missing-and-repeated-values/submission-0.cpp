typedef long long int ll;
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        ll sq = 1LL * n * n;
        ll sum = 1LL * (sq * (sq + 1)) / 2;
        ll sumSq = 1LL * (sq * (sq + 1) * (2 * sq + 1)) / 6;
        ll gridSum = 0, gridSumSq = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                gridSum += 1LL * grid[i][j];
                gridSumSq += 1LL * grid[i][j] * grid[i][j];
            }
        }

        ll normalDiff = gridSum - sum;
        ll sqDiff = gridSumSq - sumSq;
        ll s = sqDiff / normalDiff;

        int a = (s + normalDiff) / 2;
        int b = s - a;

        return {a, b};
    }
};