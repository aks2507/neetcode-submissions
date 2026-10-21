class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);

        for (auto& vec : prerequisites) {
            int course = vec[0];
            int prereq = vec[1];
            graph[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        int finished = 0;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                finished++;
            }
        }

        
        while (!q.empty()) {
            int course = q.front();
            q.pop();

            for (auto& sub : graph[course]) {
                indegree[sub]--;
                if (indegree[sub] == 0) {
                    finished++;
                    q.push(sub);
                }
            }
        }

        return numCourses == finished;
    }
};
