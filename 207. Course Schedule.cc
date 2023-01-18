// Using topological sort (kahn's algorithm based on BFS)
// TC: O(V+E)
// SC: O(V+E)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        //O(E)
        for (auto &p: prerequisites) {
            adjList[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        //O(V)
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);

            }
        }
        
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            numCourses--;
            for (auto vertex: adjList[curr]) {
                if(--indegree[vertex] == 0) {
                    q.push(vertex);
                }
            }
        }
        
        
        return numCourses == 0;
        
        
    }
};