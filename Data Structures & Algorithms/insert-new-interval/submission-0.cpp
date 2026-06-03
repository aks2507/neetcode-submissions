class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int l = 0, r = intervals.size();
        int start = newInterval[0];
        int end = newInterval[1];
        while(l < r) {
            int mid = (l + r) / 2;
            if (start > intervals[mid][1]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        int left = l;
        
        l = 0, r = intervals.size();
        while(l < r) {
            int mid = (l + r) / 2;
            if (intervals[mid][0] <= end) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        int right = l;

        vector<vector<int>> res;
        
        for(int i = 0; i < left; i++) {
            res.push_back(intervals[i]);
        }

        vector<int> merged = newInterval;
        if(left < right) {
            merged[0] = min(newInterval[0], intervals[left][0]);
            merged[1] = max(newInterval[1], intervals[right - 1][1]);
        }

        res.push_back(merged);

        for(int i = right; i < intervals.size(); i++) {
            res.push_back(intervals[i]);
        }

        return res;
    }
};
