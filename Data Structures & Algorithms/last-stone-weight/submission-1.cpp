class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(auto& n: stones) {
            maxHeap.push(n);
        }

        while(maxHeap.size() > 1) {
            int a = maxHeap.top();
            maxHeap.pop();
            int b = maxHeap.top();
            maxHeap.pop();

            if(a != b) {
                int diff = abs(a - b);
                maxHeap.push(diff);
            }
        }

        return maxHeap.size() == 0 ? 0 : maxHeap.top();
    }
};
