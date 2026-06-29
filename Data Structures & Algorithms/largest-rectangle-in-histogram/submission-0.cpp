class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;

        stack<pair<int, int>> s;

        for(int i = 0; i < n; i++) {
            int start = i;
            while(!s.empty() && s.top().second > heights[i]) {
                pair<int, int> top = s.top();
                int index = top.first;
                int height = top.second;

                maxArea = max(maxArea, height * (i - index));

                start = index;
                s.pop();
            }

            s.push({start, heights[i]});
        }

        while(!s.empty()) {
            pair<int, int> top = s.top();
            int index = top.first;
            int height = top.second;

            maxArea = max(maxArea, height * (n - index));
            s.pop();
        }

        return maxArea;
    }
};
