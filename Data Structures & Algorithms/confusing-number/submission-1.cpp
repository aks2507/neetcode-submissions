class Solution {
private:
    // unordered_set<int> rotatable = {0, 1, 6, 8, 9};
    unordered_map<int, int> rotateMap = {
        {0, 0},
        {1, 1},
        {6, 9},
        {8, 8},
        {9, 6}
    };
    bool isRotatable(int n) {
        return rotateMap.count(n);
    }
public:
    bool confusingNumber(int n) {
        int initial = n;
        int newNum = 0;
        while(n > 0) {
            int r = n % 10;
            if (!isRotatable(r)) {
                return false;
            }
            newNum = (newNum + rotateMap[r]) * 10;
            n = n / 10;
        }
        newNum = newNum / 10;

        return initial != newNum;
    }
};
