//using DFS(backtracking) method
//TC: O(row * col * (4 ^ length of word))
//SC: O(4 * length of word)
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        //prune 1:
        if (word.size() > row * col) {
            return false;
        }
        //prune 2:
        map<char, int> m;
        for (int i = 0; i < row * col; i++) { 
            m[board[i / col][i % col]]++;
        }
        
        for (const auto &i : word) {
            m[i]--;
            if (m[i] < 0)
                return false;
        }
        
        //prune 3:
        int left_pref = word.find_first_not_of(word[0]);
        int right_suf = word.size() - word.find_last_not_of(word.back());
        if (left_pref > right_suf) {
            reverse(word.begin(), word.end());
        }
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == word[0] && DFS(i, j, 0, board, word))
                    return true;
                
            }
        }
        
        return false;
    }
    
    
    bool DFS(int i, int j, int n, vector<vector<char>>& board, string &word) {
        if (n == word.size())
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[n])
            return false;
        //mark board[i][j] as already visited
        board[i][j] = '1';
        
        bool status = DFS(i - 1, j, n + 1, board, word) || //Up
                        DFS(i + 1, j, n + 1, board, word) || //down
                        DFS(i, j - 1, n + 1, board, word) || //left
                        DFS(i, j + 1, n + 1, board, word); //right
        board[i][j] = word[n];
        return status;
    }
    
    
    
};