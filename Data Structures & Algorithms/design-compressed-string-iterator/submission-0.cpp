class StringIterator {
private:
    bool isAlpha(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    bool isNum(char c) {
        return (c >= '0' && c <= '9');
    }

    vector<char> characters;
    vector<int> reps;
    int ptr = 0;
public:
    StringIterator(string compressedString) {
        int idx = 0;
        while (idx < compressedString.length()) {
            if (isAlpha(compressedString[idx])) {
                characters.push_back(compressedString[idx]);
                idx++;
            } else {
                string s = "";
                while(isNum(compressedString[idx])) {
                    s += compressedString[idx++];
                }
                reps.push_back(stoi(s));
            }
        }

        for (int i = 0; i < characters.size(); i++) {
            cout << characters[i] << " -> " << reps[i] << endl;
        }
    }
    
    char next() {
        if (reps[ptr] == 0) {
            ptr++;   
        }
        reps[ptr]--;
        return characters[ptr];
    }
    
    bool hasNext() {
        if (!(ptr == characters.size() && reps[ptr] == 0)) {
            return true;
        }

        return false;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
