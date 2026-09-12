class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int maxarea = INT_MIN;
        while(l < r) {
            int area = min(heights[l], heights[r]) * (r - l);
            maxarea = max(maxarea, area);
            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }

        return maxarea;
    }
};
