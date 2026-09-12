class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxLeft(n, 0);
        vector<int> maxRight(n, 0);
        maxLeft[0] = height[0];
        maxRight[n - 1] = height[n - 1];

        for (int i = 0; i < n; i++) {
            if (i > 0) {
                maxLeft[i] = max(maxLeft[i - 1], height[i]);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1) {
                maxRight[i] = max(maxRight[i + 1], height[i]);
            }
        }

        // for (int i = 0; i < n; i++) {
        //     cout << maxLeft[i] << ", ";
        // }
        // cout << endl;

        // for (int i = 0; i < n; i++) {
        //     cout << maxRight[i] << ", ";
        // }
        // cout << endl;

        int water = 0;
        for (int i = 0; i < n; i++) {
            water += min(maxLeft[i], maxRight[i]) - height[i];
        }

        return water;
    }
};
