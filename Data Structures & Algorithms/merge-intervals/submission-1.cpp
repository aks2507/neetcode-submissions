class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        for(int i = 0; i < n; i++) {
            int m = res.size();
            if(res.empty() || res[m - 1][1] < intervals[i][0]) {
                res.push_back(intervals[i]);
            } else {
                // vector<int> interval(2, -1);
                // interval[0] = res[m - 1][0];
                // interval[1] = max(intervals[i][1], res[m - 1][1]);
                // res.pop_back();
                // res.push_back(interval);
                res[m - 1][1] = max(intervals[i][1], res[m - 1][1]);
            }
        }

        return res;
    }
};
