//TC: O(logn)
//SC: O(1)
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x) {
            int remainder = x % 10;
            //INT_MAX: 2147483647
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && remainder > 7)) {
                return 0;
            }
            //INT_MIN: -2147483648
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && remainder < -8)) {
                return 0;
            }
            rev = rev * 10 + remainder;
            x /= 10;
        }
        return rev;
    }
};