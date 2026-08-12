class Solution {
private:
    int m = 0, n = 0;
    int minDistRec(int i, int j, string word1, string word2, vector<vector<int>>& mem) {
        if (i == m) {
            return n - j;
        }

        if (j == n) {
            return m - i;
        }

        if (mem[i][j] != -1) {
            return mem[i][j];
        }
        
        if (word1[i] == word2[j]) {
            mem[i][j] = minDistRec(i + 1, j + 1, word1, word2, mem);
        } else {
            int insert = minDistRec(i + 1, j, word1, word2, mem);
            int del = minDistRec(i, j + 1, word1, word2, mem);
            int replace = minDistRec(i + 1, j + 1, word1, word2, mem);

            mem[i][j] = 1 + min(replace, min(del, insert));
        }

        return mem[i][j];
    }
public:
    int minDistance(string word1, string word2) {
        if (word1 == word2) {
            return 0;
        }
        m = word1.length();
        n = word2.length();

        vector<vector<int>> mem(m, vector<int>(n, -1));

        return minDistRec(0, 0, word1, word2, mem);
    }
};
