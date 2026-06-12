class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        int n = position.size();

        for(int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end());
        vector<double> s;
        for(int i = n - 1; i >= 0; i--) {
            s.push_back((double)(target - cars[i].first) / cars[i].second);
            if (s.size() > 1 && s.back() <= s[s.size() - 2]) {
                s.pop_back();
            }
        }

        return s.size();
    }
};
