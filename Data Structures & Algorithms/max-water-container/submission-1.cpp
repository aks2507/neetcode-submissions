class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;

        int max_area = INT_MIN;
        while(l < r) {
            int area = min(heights[l], heights[r]) * (r - l);
            max_area = max(area, max_area);

            if(heights[l] <= heights[r]) {
                l++;
            } else {
                r--;
            }
        }

        return max_area;
    }
};
