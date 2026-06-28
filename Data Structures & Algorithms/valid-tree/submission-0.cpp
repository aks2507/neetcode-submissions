class Solution {
private:
    bool dfs(int node, int parent, unordered_set<int>& visited, vector<vector<int>>& adjacencyList) {
        if (visited.count(node)) {
            return false;
        }
        
        visited.insert(node);
        for(auto& neighbour:adjacencyList[node]) {
            if (neighbour == parent) {
                continue;
            }

            if(!dfs(neighbour, node, visited, adjacencyList)) {
                return false;
            }
        }

        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int e = edges.size();

        if (e > n - 1) {
            return false;
        }

        vector<vector<int>> adjacencyList(n);

        for(auto& edge: edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visited;

        if (!dfs(0, -1, visited, adjacencyList)) {
            return false;
        }

        return visited.size() == n;
    }
};
