typedef pair<int, pair<int, int>> ppi;
class Solution {
public:
    double dist(int x, int y) {
        return x * x + y * y;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<ppi> maxHeap;
        for(auto& point: points) {
            maxHeap.push({dist(point[0], point[1]), {point[0], point[1]}});
            if(maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<vector<int>> res;
        while(!maxHeap.empty()) {
            ppi a = maxHeap.top();
            pair<int, int> coordinates = a.second;
            vector<int> cd(2);
            cd[0] = coordinates.first;
            cd[1] = coordinates.second;
            res.push_back(cd);
            maxHeap.pop();
        }

        return res;
    }
};
