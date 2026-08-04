class TrieNode {
public:
    int wordIdx = -1;
    unordered_map<char, TrieNode*> children;

    void addWord(string s, int idx) {
        TrieNode* curr = this;
        for(char c : s) {
            if (!curr->children.count(c)) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }

        curr->wordIdx = idx;
    }
};

class Solution {
private:
    vector<vector<int>> directionVectors = {
        {0, 1},
        {1, 0}, 
        {0, -1},
        {-1, 0}
    };

    TrieNode* root = nullptr;
    int rows = 0, cols = 0;
    vector<string> res;

    bool isValidCell(int row, int col) {
        return row >= 0 && row < rows && col >= 0 && col < cols;
    }

    void searchDfs(int row, int col, TrieNode* root, vector<vector<bool>>& visited, vector<vector<char>>& board, vector<string>& words) {
        if (!isValidCell(row, col) || visited[row][col]) {
            return;
        }

        char currChar = board[row][col];
        if (!root->children.count(currChar)) {
            return;
        }

        TrieNode* nextNode = root->children[currChar];
        if (nextNode->wordIdx != -1) {
            res.push_back(words[nextNode->wordIdx]);
            nextNode->wordIdx = -1;
        }

        visited[row][col] = true;

        for (auto& vec : directionVectors) {
            int nextRow = row + vec[0];
            int nextCol = col + vec[1];
            searchDfs(nextRow, nextCol, nextNode, visited, board, words);
        }

        visited[row][col] = false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        rows = board.size();
        cols = board[0].size();

        root = new TrieNode();
        for (int i = 0; i < words.size(); i++) {
            root->addWord(words[i], i);
        }
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                searchDfs(i, j, root, visited, board, words);
            }
        }

        return res;
    }
};
