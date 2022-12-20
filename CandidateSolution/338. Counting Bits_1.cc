//TC: O(n)
//SC: O(1)
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1, 0);
        if (num == 0) 
            return dp;
        dp[1] = 1;
        int k = 2;
        int i = 2;
        while (i <= num) {
            for (i = pow(2, k - 1); i < pow(2, k); ++i) {
                if (i > num) 
                    break;
                int t = (pow(2, k) - pow(2, k - 1)) / 2;
                if (i < pow(2, k - 1) + t) 
                    dp[i] = dp[i - t];
                else 
                    dp[i] = dp[i - t] + 1;
            }
            ++k;
        }
        return dp;
    }
};


/*
2 10 1
3 11 2
-----------
4 100 1
5 101 2
6 110 2
7 111 3
-----------
8  1000 1
9  1001 2
10 1010 2
11 1011 3
12 1100 2
13 1101 3
14 1110 3
15 1111 4
*/