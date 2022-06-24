//Using DFS method
//TC: O(mn)
//SC: O(mn) (worst case)
class Solution {
public:
    int n;
    int m;
    void Dfs(vector<vector<char>>& grid, int r, int c) {
        
        if (r < 0  || r >= m || c < 0 || c >= n || grid[r][c] == '0') {
            return;
        }    
            grid[r][c] = '0';
            Dfs(grid, r - 1, c);
            Dfs(grid, r + 1, c);
            Dfs(grid, r, c - 1);
            Dfs(grid, r, c + 1);
    }
    
    
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        
        m = grid.size();
        n = grid[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    Dfs(grid, i, j);
                }
            }
        }
        
        return ans;
        
    }
};