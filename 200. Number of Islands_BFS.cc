//Using DFS method
//TC: O(mn)
//SC: O(min(m, n)) //traverse layer by layer
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        queue<int> lands;
        vector<pair<int,int>> dir{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    lands.push(i * n + j);
                    //Every element in the queue executes at most 4 times.
                    //If grid is filled with 1, then m * n elements will be in the queue.
                    while (lands.size() != 0) {
                        int index = lands.front();
                        lands.pop();
                        for (auto d : dir) {
                            int r = index / n + d.first;
                            int c = index % n + d.second;
                            if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == '0') {
                                continue;
                            }
                            lands.push(r * n + c);
                            grid[r][c] = '0';
                        }
                    }
                }
                
                
            }
        }
        return ans;
    }
};