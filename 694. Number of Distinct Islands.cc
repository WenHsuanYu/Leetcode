// TC: O(mn)
// SC: O(mn)
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int row;
    int col;
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    unordered_set<string> set;
    int numDistinctIslands(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j]) {
                    string code = "";
                    dfs(i, j, grid, code);
                    set.insert(code);
                }
            }
        }
        return set.size();
    }
    void dfs(int r, int c, vector<vector<int>> &grid, string &code) {
        grid[r][c] = 0;
        for (int i = 0; i < (int)dirs.size(); ++i) {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || !grid[nr][nc]) {
                continue;
            }
            code += to_string(i) + ",";
            dfs(nr, nc, grid, code);
        }
    }
};


int main(int argc, char** argv){
    Solution solution;
    vector<vector<int>> grid{{1,1,1,0,0,0}, {1,1,1,0,0,0}, {0,0,0,1,1,0}, {0,0,0,1,1,1}};
    int res = solution.numDistinctIslands(grid);
    cout << setw(3) << res << endl;
    return 0;
}
