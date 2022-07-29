// TC: O(logn)
// SC: O(logn)

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) 
            return 1;
        
        double half = myPow(x, n / 2);
        
        if (n % 2 == 0) { 
            return half * half;
        }
        //n = 1, 3, 5....
        if (n > 0) {
            return half * half * x;
        }
        //n = -1, -3, -5....
        return half * half / x;
        
    }

};
