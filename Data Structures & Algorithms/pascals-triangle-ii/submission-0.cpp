class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row = {1};
        for (int i = 1; i <= rowIndex; i++) {
            row.push_back(
                (int)(1LL * row.back() * (rowIndex - i + 1) / i)
            );
        }

        return row;
    }
};