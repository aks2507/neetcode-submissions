typedef pair<int, int> pp;
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pp, vector<pp>, greater<pp>> minHeap;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            minHeap.push({nums[i], i});
        }

        while(k--) {
            pp min = minHeap.top();
            minHeap.pop();

            min.first *= multiplier;
            minHeap.push(min);
        }

        vector<int> res(n, 0);

        while(!minHeap.empty()) {
            pp p = minHeap.top();
            minHeap.pop();
            res[p.second] = p.first;
        }

        return res;
    }
};