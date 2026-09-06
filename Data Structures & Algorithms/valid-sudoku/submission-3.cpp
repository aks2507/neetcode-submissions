class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int, unordered_set<char>> rows, cols;
        map<pair<int, int>, unordered_set<char>> boxes;
        for(int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                char element = board[row][col];
                if (element == '.') {
                    continue;
                }
                pair<int, int> p = {row / 3, col / 3};
                if (rows[row].count(element) || cols[col].count(element) || boxes[p].count(element)) {
                    return false;
                }

                rows[row].insert(element);
                cols[col].insert(element);
                boxes[p].insert(element);
            }
        }

        return true;
    }
};
