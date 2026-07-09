class TrieNode {
public:
    bool endOfWord = false;
    unordered_map<char, TrieNode*> children;
};
class WordDictionary {
private:
    TrieNode* root;

    bool searchDfs(string word, int i, TrieNode* root) {
        if (!root) {
            return false;
        }

        if (i >= word.length()) {
            return root->endOfWord;
        }

        char c = word[i];

        if (c != '.') {
            if (!root->children.count(c)) {
                return false;
            }

            return searchDfs(word, i + 1, root->children[c]);
        } 
        
        for (auto& [ch, node] : root->children) {
            if (node != nullptr && searchDfs(word, i + 1, node)) {
                return true;
            }
        }
    
        return false;
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* temp = root;
        for (char c : word) {
            if (!temp->children.count(c)) {
                temp->children[c] = new TrieNode();
            }

            temp = temp->children[c];
        }

        temp->endOfWord = true;
    }
    
    bool search(string word) {
        return searchDfs(word, 0, root);
    }
};
