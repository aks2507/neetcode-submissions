class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0, r = n - 1;
        int res = 0, vol = 0;
        while(l < r) {
            vol = min(heights[r], heights[l]) * (r - l);
            if (heights[l] < heights[r]) {
                l++;
            } else if (heights[l] > heights[r]) {
                r--;
            } else {
                l++;
            }
            res = max(res, vol);
        }

        return res;
    }
};
