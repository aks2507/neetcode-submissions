class Solution {
public:
    // int recMinCost(vector<int>& cost, int i) {
    //     if (i >= cost.size()) {
    //         return 0;
    //     }

    //     return cost[i] + min(recMinCost(cost, i + 1), recMinCost(cost, i + 2));
    // }
    
    int minCostDp(vector<int>& cost, vector<int>& costStore, int i) {
        if (i >= cost.size()) {
            return 0;
        }

        if (costStore[i] != -1) {
            return costStore[i];
        }

        costStore[i] = cost[i] + min(minCostDp(cost, costStore, i + 1), minCostDp(cost, costStore, i + 2));

        return costStore[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // return min(recMinCost(cost, 0), recMinCost(cost, 1));

        vector<int> costStore(cost.size(), -1);
        return min(minCostDp(cost, costStore, 0), minCostDp(cost, costStore, 1));
    }
};
