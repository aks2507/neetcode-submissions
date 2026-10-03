typedef pair<int, int> pp;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int num : nums) {
            mp[num]++;
        }

        priority_queue<pp, vector<pp>, greater<pp>> pq;

        for (auto& [n, f] : mp) {
            pq.push({f, n});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
