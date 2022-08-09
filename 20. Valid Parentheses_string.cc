//Using string to simulate stack
//TC: O(n)
//SC: O(n)
class Solution {
public:
    bool isValid(string s) {
        string stack = "";
        for(char c: s) {
            if (c == '(') {
                stack.push_back(')');
            } else if (c == '{') {
                stack.push_back('}');
            } else if (c == '[') {
                stack.push_back(']');
            } else if (c == ')' || c == '}' || c == ']') {
                if (c != stack.back()) {
                    return false;
                }
                stack.pop_back();
                /* nothing special */
             } else {
                  return false;
            }
        }
        return stack.length() == 0;
    }
};