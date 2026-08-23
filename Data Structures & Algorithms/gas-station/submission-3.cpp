class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), totalDiff = 0;
        for (int i = 0; i < n; i++) {
            totalDiff += gas[i] - cost[i];
        }
        if (totalDiff < 0) {
            return -1;
        }

        int total = 0, res = 0;
        for (int i = 0; i < n; i++) {
            total += gas[i] - cost[i];

            if (total < 0) {
                total = 0;
                res = i + 1;
            }
        }

        return res;
    }
};
