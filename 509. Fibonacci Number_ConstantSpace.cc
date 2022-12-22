// TC: O(n)
// SC: O(1)
class Solution {
public:
    int fib(int n) {
        int prev = 0;
        int last = 1;
        int result = 0;
        for (int i = 2; i <= n; i++) {
            result = prev + last;
            prev = last;
            last = result;
        }
        return n > 1 ? result : n;
    }
};