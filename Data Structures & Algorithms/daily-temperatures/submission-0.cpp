class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> unresolved_idx;
        vector<int> res(n, 0);

        for (int i = 0; i < n; i++) {
            while (!unresolved_idx.empty() && temperatures[i] > temperatures[unresolved_idx.top()]) {
                res[unresolved_idx.top()] = i - unresolved_idx.top();
                unresolved_idx.pop();
            }

            unresolved_idx.push(i);
        }

        return res;
    }
};
