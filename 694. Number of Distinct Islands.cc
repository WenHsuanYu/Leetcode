// TC: O(mn)
// SC: O(mn)
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        unordered_set<string>res;
        vector<vector<int>>visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    set<string> s;
                    helper(grid, i, j, i, j, visited, s);
                    string tmp = "";
                    for (auto str : s) {
                        tmp += str + "-";
                    }
                    res.insert(tmp);
                }
            }
        }
        for (auto str : res) {
            cout << str << endl;
        }
        return res.size();

    }
    void helper(vector<vector<int>>& grid, int x0, int y0, int i, int j, vector<vector<int>>& visited, set<string>& s) {
        int m = grid.size();
        int n = grid[0].size();
        visited[i][j] = 1;
        for (auto dir : dirs) {
            int x = i + dir[0];
            int y = j + dir[1];
            if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || grid[x][y] == 0) {
                continue;
            }
            string str = to_string(x - x0) + "_" + to_string(y - y0);
            s.insert(str);
            helper(grid, x0, y0, x, y, visited, s);
        }        
    }
};
/*
**int main(int argc, char* argv[]) {
**  Solution solution;
**  vector<vector<int>> grid{{1,1,1,0,0,0}, {1,1,1,0,0,0}, {0,0,0,1,1,0}, {0,0,0,1,1,1}};
**  int res = solution.numDistinctIslands(grid);
**  cout << setw(3) << res << endl;
**  return 0;
**};
*/