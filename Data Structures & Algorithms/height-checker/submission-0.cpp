class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> count(101, 0);

        for (int h : heights) {
            count[h]++;
        }
        
        vector<int> expected;
        for (int i = 1; i <= 100; i++) {
            int c = count[i];
            for (int j = 0; j < c; j++) {
                expected.push_back(i);
            }
        }

        int res = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != expected[i]) {
                res++;
            }
        }

        return res;
    }
};