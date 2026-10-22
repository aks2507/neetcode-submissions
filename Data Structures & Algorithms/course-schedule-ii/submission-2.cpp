class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> graph(numCourses);

        for (auto& vec: prerequisites) {
            // int course = vec[0];
            // int prereq = vec[1];
            graph[vec[1]].push_back(vec[0]);
            indegree[vec[0]]++;
        }

        queue<int> q;
        vector<int> order;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                order.push_back(i);
            }
        }

        while (!q.empty()) {
            int course = q.front();
            q.pop();
            
            for (auto& depCourse : graph[course]) {
                indegree[depCourse]--;
                if (indegree[depCourse] == 0) {
                    order.push_back(depCourse);
                    q.push(depCourse);
                }
            }
        }
        if (order.size() != numCourses) {
            return {};
        }
        return order;
    }
};
