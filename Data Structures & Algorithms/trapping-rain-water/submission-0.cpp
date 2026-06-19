class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxLeft(n);
        vector<int> maxRight(n);
        maxLeft[0] = height[0];
        maxRight[n - 1] = height[n - 1];
        for(int i = 1; i < n; i++) {
            maxLeft[i] = max(maxLeft[i - 1], height[i]);
            maxRight[n - i - 1] = max(maxRight[n - i], height[n - i - 1]);
        }
        
        int water = 0;
        for(int i = 0; i < n; i++) {
            water += min(maxLeft[i], maxRight[i]) - height[i];
        }

        return water;
    }
};
