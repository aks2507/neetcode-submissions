class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses, 0);
        vector<int> res;
        vector<vector<int>> graph(numCourses);

        for(auto& dep:prerequisites) {
            int prerequisite = dep[1];
            int course = dep[0];

            graph[prerequisite].push_back(course);
            indegrees[course]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegrees[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int prereq = q.front();
            q.pop();
            res.push_back(prereq);
            for(int course:graph[prereq]) {
                indegrees[course]--;
                if(indegrees[course] == 0) {
                    q.push(course);
                }
            }
        }

        return res.size() == numCourses ? res : vector<int>(0);
    }
};
