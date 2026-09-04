class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);

        for (auto& prerequisite : prerequisites) {
            int course = prerequisite[0];
            int dependency = prerequisite[1];

            graph[dependency].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int finished = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            finished++;
            for (int neighbour : graph[course]) {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        return finished == numCourses;
    }   
};
