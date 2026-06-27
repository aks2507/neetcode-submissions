class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int> indegrees(numCourses, 0);
        vector<vector<int>> graph(numCourses);

        for(auto& dep: prerequisites) {
            int course = dep[0];
            int prerequisite = dep[1];
            graph[course].push_back(prerequisite);
            indegrees[prerequisite]++;
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++) {
            if (indegrees[i] == 0) {
                q.push(i);
            }
        }

        int finished = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            finished++;
            for(int neighbor:graph[node]) {
                indegrees[neighbor]--;
                if(indegrees[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return finished == numCourses;
    }   
};
