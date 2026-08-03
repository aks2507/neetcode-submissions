class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) {
            return {{1}};
        }
        if (numRows == 2) {
            return {{1}, {1, 1}};
        }

        vector<vector<int>> res = {
            {1},
            {1, 1}
        };
        int k = 2;
        while (k < numRows) {
            vector<int> vec = res[k - 1];
            vector<int> next = {1};
            for (int i = 0; i < vec.size() - 1; i++) {
                next.push_back(vec[i] + vec[i + 1]);
            }
            next.push_back(1);
            res.push_back(next);
            k++;
        }

        return res;
        
    }
};