// TC: O(logn)
// SC: O(1)

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int palindrome[10];
        int len = 0;
        while (x) {
            palindrome[len] = x % 10;
            x /= 10;
            len++;
        }
       
        for (auto i = 0; i < len / 2; i++) {
            if(palindrome[0 + i] != palindrome[len - 1 -i]) {
                return false;
            }
        }
        
        return true;
    }
};