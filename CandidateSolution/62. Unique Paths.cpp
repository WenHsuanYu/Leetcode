//Using combination method of Math 
class Solution {
public:
    int uniquePaths(int m, int n) {
        
        long long path = 1;
        /*
        * (m-1 + n -1)! / [(m-1)!(n-1)!] = (m + n - 2)(m + n - 3)....n / (m - 1)!
        * = (m + n - 2)(m + n - 3)....n / [(m + n - 2 - n + 1)(m + n - 3 - n + 1).....(n - n + 1)]
        * let i = n to (m + n -2)
        */
        for (int i = n; i < n + m -1; i++) {
            path *= i;
            path /= (i - n + 1);
        }
        
        return path;
    }
};