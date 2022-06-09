#define attack 0
#define not_attack 1

//created by prime_tang
//modified by Alex-Yu

class Solution {
public:
    vector<vector<string>> ans;
    std::vector<std::vector<std::string> > solveNQueens(int n) {
        std::vector<std::vector<std::string> > res;
        std::vector<std::string> nQueens(n, std::string(n, '.'));
        /*
        flag[0] to flag[n - 1] to indicate if the column had a queen before.
        flag[n] to flag[3 * n - 2] to indicate if the 45° diagonal had a queen before.
        flag[3 * n - 1] to flag[5 * n - 3] to indicate if the 135° diagonal had a queen before.
        */
        std::vector<int> flag(5 * n - 2, not_attack);
        solveNQueens(nQueens, flag, 0, n);
        return ans;
    }
private:
    template<class T, class U, class V>
    void solveNQueens(T &nQueens, U &flag, V row, V &n) {
        if (row == n) {
            ans.push_back(nQueens);
            return;
        }
        for (int col = 0; col != n; ++col)
            if (flag[col] && flag[n + row + col] && flag[4 * n - 2 + row - col]) {
                flag[col] = flag[n + row + col] = flag[4 * n - 2 + row - col] = attack;
                nQueens[row][col] = 'Q';
                solveNQueens(nQueens, flag, row + 1, n);
                nQueens[row][col] = '.';
                flag[col] = flag[n + row + col] = flag[4 * n - 2 + row - col] = not_attack;
            }
    }
};