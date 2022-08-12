//TC: O(logn)
//SC: O(1)
class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        
        if (x < 0 && x != INT_MIN) {
            x = abs(x);
            sign = -1;
        } else if (x == INT_MIN) {
            return 0;
        }
        int res = 0;
        while (x != 0) {
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && (x % 10 > INT_MAX % 10)))
                return 0;
            res *= 10;
            res += (x % 10);
            x /= 10;
        }

        
        return res * sign;
    }
};