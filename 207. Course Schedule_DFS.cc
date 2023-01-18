// Using topological sort (DFS)
// TC: O(V+E)
// SC: O(V+E)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> adjList(numCourses, vector<int>());
        //0: unvisited 1: visiting 2: visited
        vector<int> vnode(numCourses, 0);
        // vector<bool> done(numCourses, false);
        for (const auto &p: pre) {
            adjList[p[1]].push_back(p[0]);
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (!vnode[i] && !isAscylic(adjList, vnode, i)) {
                return false;
            }
        }
        return true;
    }
    
private:
    bool isAscylic(vector<vector<int>>& adjList, vector<int> &vnode, int i) {
        //have a cycle
        if (vnode[i] == 1) {
            return false;
        }
        //There is a path from A to B (visited), but B can not arrive A. Otherwise, when B as root started traversing, B should find A at that time.
        if (vnode[i] == 2) {
            return true;
        }
        vnode[i] = 1;
        for (const int &vec: adjList[i]) {
            if (!isAscylic(adjList, vnode, vec)) {
                return false;
            }
        }
        vnode[i] = 2;
        return true;
    }
    
};