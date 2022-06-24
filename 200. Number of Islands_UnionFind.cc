//Using Union-Find method
//TC: O(mn)
//SC: O(mn)
//Every island finally has a fixed index which is also the discovered last.

class Solution {
public:
    //path compression
    int find(int index, vector<int>& parent) {
        if (parent[index] != index)
            parent[index] = find(parent[index], parent);
        return parent[index];
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> parent(n * m);
        
        for (int i = 0; i < n * m; i++) {
            parent[i] = i;
        }
        //Up and left
        vector<pair<int,int>> dir{{-1, 0}, {0, -1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    int p1 = find(i * n + j, parent);
                    //Up and left directions
                    for (auto k : dir) {
                        int r = i + k.first;
                        int c = j + k.second;
                        if (r >= 0 &&  c >= 0 && r < m && c < n && grid[r][c] == '1') {
                            int p2 = find(r * n + c, parent);
                            if (p1 != p2) {
                                parent[p2] = p1;
                            }
                        }
                    }
                }

            }
        }
        
        int ans = 0;
        for (int i = 0; i < n * m; i++) {
            if (parent[i] == i && grid[i / n][i % n] == '1')
                ans++;
        }
        return ans;
    }

};

