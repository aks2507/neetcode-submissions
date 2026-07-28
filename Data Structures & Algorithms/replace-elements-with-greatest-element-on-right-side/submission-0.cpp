class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int maxNow = arr[n - 1];
        arr[n - 1] = -1;

        for (int i = n - 2; i >= 0; i--) {
            int max = maxNow;
            if (arr[i] >= maxNow) {
                maxNow = arr[i];
            }
            arr[i] = max;
        }

        return arr;
    }
};