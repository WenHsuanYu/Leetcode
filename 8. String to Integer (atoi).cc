// TC: O(n)
// SC: O(1)
class Solution {
public:
    int myAtoi(string s) {
        int num = 0;
        int index = 0;
        int sign = 1;
        while (s[index] == ' ') {
            index++;
        }
        
        if (s[index] == '-' || s[index] == '+') {
            sign = 1 - 2 * (s[index] == '-');
            index++;
        }
        
        
        while (s[index] >= '0' && s[index] <= '9') {
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && s[index] - '0' > INT_MAX % 10)) {
                if (sign == 1) {
                    return INT_MAX;
                } else {
                    return INT_MIN;
                }
            }
            num = num * 10 + (s[index] - '0');
            index++;
        }
        return num * sign;
    }
};