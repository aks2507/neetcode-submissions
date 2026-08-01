class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> st(arr.begin(), arr.end());
        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (st.count(arr[i] + 1)) {
                count++;
                // st.erase(arr[i] + 1);
            }
        }

        return count;
    }
};
