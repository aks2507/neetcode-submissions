class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;

        for (int i = 0; i < items.size(); i++) {
            auto& vec = items[i];
            int id = vec[0];
            int score = vec[1];
            if(mp.count(id)) {
                if (mp[id].size() < 5) {
                    mp[id].push(score);
                } else {
                    int top = mp[id].top();
                    if (top < score) {
                        mp[id].pop();
                        mp[id].push(score);
                    }
                }
            } else {
                mp[vec[0]].push(vec[1]);
            }
        }

        vector<vector<int>> res;
        for(auto& [id, heap] : mp) {
            int sum = 0;
            while(!heap.empty()) {
                sum += heap.top();
                heap.pop();
            }

            res.push_back({id, sum / 5});
        }

        sort(res.begin(), res.end());
        return res;
    }
};
