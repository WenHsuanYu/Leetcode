class Solution {
public:
    int myAtoi(string s) {
        char sign = ' ';
        string res = "";
        int len = s.length();
        long long num = 0;
        int i = 0;
        for (i = 0; i < len; i++) {
            if (s[i] != ' ') { 
                break;
            }
        }
                
        for (i; i < len; i++) {

            if (sign == ' ' && (s[i] == '-' || s[i] == '+')) {
                sign = s[i];
                continue; 
            } else if (sign != ' ' && (s[i] == '-' || s[i] == '+')) {
                return num;
            }
     
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == '.' || s[i] == ' ') {
                break;
            }
            int operand = 0;        
            if (sign == '-') {
                num *= 10;
                operand = (s[i] - '0') * -1;
                if (num + operand > INT_MIN) {
                    num += operand;
                } else {
                    return INT_MIN;
                }
            } else {
                num *= 10;
                operand = s[i] - '0';
                if (num + operand < INT_MAX) {
                    num += operand;
                } else {
                    return INT_MAX;
                }
                sign = '+';
            }

        }
    
        return num;
    }
};