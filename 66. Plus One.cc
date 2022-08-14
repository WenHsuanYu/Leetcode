// TC: O(n)
// SC: O(1)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int carry = 0;
        digits[len - 1]++;
        for (int i = len - 1; i >= 0; i--) {
            digits[i] += (carry == 1 ? 1 : 0);
            carry = digits[i] == 10 ? 1 : 0;
            digits[i] = digits[i] == 10 ? 0 : digits[i];
        }
        if (carry == 1) {
            digits.insert(digits.begin(), 1);
            carry = !carry;
        }
        return digits;
    }
};