class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> graph(numCourses);
        for (auto& vec : prerequisites) {
            int course = vec[0];
            int prerequisite = vec[1];
            graph[prerequisite].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        vector<int> res;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int course = q.front();
            q.pop();
            res.push_back(course);
            auto& neighbors = graph[course];
            for (int i = 0; i < neighbors.size(); i++) {
                indegree[neighbors[i]]--;
                if (indegree[neighbors[i]] == 0) {
                    q.push(neighbors[i]);
                }
            }
        }

        return (res.size() == numCourses) ? res : vector<int>(0);
    }
};
