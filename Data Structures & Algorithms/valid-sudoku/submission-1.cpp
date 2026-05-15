class Solution {
public:
    // bool isValidSudoku(vector<vector<char>>& board) {
    //     map<int, unordered_set<char>> rows;
    //     map<int, unordered_set<char>> cols;
    //     map<int, unordered_set<char>> boxes;

    //     for (int i = 0; i < 9; i++) {
    //         for (int j = 0; j < 9; j++) {
    //             if (board[i][j] == '.') {
    //                 continue;
    //             }
    //             if(rows[i].find(board[i][j]) != rows[i].end()) {
    //                 // cout << "return 1-if false at i = " << i << " and j = " << j << endl;
    //                 return false;
    //             } else {
    //                 rows[i].insert(board[i][j]);
    //             }
                
    //             if (cols[j].find(board[i][j]) != cols[j].end()) {
    //                 // cout << "return 2-if false at i = " << i << " and j = " << j << endl;
    //                 return false;
    //             } else {
    //                 cols[j].insert(board[i][j]);
    //             }
    //             if (boxes[(i / 3) * 3 + j / 3].find(board[i][j]) != boxes[(i / 3) * 3 + j / 3].end()) {
    //                 // cout << "i: " << i << " and j: " << j << ", Box number: " << (i / 3) * 3 + j / 3 << endl;
    //                 // cout << "return 3-if false at i = " << i << " and j = " << j << endl;
    //                 return false;
    //             } else {
    //                 boxes[(i / 3) * 3 + j / 3].insert(board[i][j]);
    //             }
                
    //         }
    //     }

    //     return true;
    // }

    bool isValidSudoku(vector<vector<char>>& board) {
        // Maintain a hash set for each row, column and 3x3 box. Any repitition returns false
        map<int, unordered_set<char>> rows;
        map<int, unordered_set<char>> cols;
        map<pair<int, int>, unordered_set<char>> boxes;

        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[r].size(); c++) {
                if (board[r][c] == '.') {
                    continue;
                }

                // check the row set. If not present push
                if (rows[r].find(board[r][c]) != rows[r].end()) {
                    return false;
                } else {
                    rows[r].insert(board[r][c]);
                }

                // check the column set. If not present push
                if (cols[c].find(board[r][c]) != cols[c].end()) {
                    return false;
                } else {
                    cols[c].insert(board[r][c]);
                }

                // check the 3x3 box set. If not present push. In a 9x9 sudoko, there are 9 boxes each of size 3x3. 
                // So to index the boxes as a matrix, do integer division by 3 for both row and col index
                pair<int, int> key = {r / 3, c / 3};
                if (boxes[key].find(board[r][c]) != boxes[key].end()) {
                    return false;
                } else {
                    boxes[key].insert(board[r][c]);
                }
            }
        }

        return true;
    }
};
