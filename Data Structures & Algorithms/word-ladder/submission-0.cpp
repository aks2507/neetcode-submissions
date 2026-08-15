class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) {
            return 0;
        }

        unordered_set<string> front = {beginWord};
        unordered_set<string> back = {endWord};

        dict.erase(beginWord);
        dict.erase(endWord);

        int length = 1;
        while (!front.empty() && !back.empty()) {
            if (front.size() > back.size()) {
                swap(front, back);
            }

            unordered_set<string> nextFront;
            for (string word : front) {
                for (int i = 0; i < word.length(); i++) {
                    char original = word[i];
                    for (char replace = 'a'; replace <= 'z'; replace++) {
                        word[i] = replace;

                        if (back.count(word)) {
                            return length + 1;
                        }

                        if (dict.count(word)) {
                            nextFront.insert(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = original;
                }
            }
            front = move(nextFront);
            length++;
        }

        return 0;
    }
};
