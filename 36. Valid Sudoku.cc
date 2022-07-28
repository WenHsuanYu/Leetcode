// TC: O(9 * 9 * log 9)
// SC: O(9 * 3)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        
        vector<set<int>> rows(9);
        vector<set<int>> cols(9);
        vector<set<int>> boxes(9);
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                
                if (board[i][j] == '.') {
                    continue;
                }                
                int curr = board[i][j] - '0';               
                if (rows[i].count(curr) || cols[j].count(curr) || boxes[(i / 3) * 3 + j / 3].count(curr)) {
                    return false;
                }
                
                rows[i].insert(curr);
                cols[j].insert(curr);
                boxes[(i / 3) * 3 + j / 3].insert(curr);
                
            }
        }
        
        return true;
    }
};