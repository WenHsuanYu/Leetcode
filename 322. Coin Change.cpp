// TC: O(n * amount)
// SC: O(amount)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> leastNumber(amount + 1, INT_MAX);
        leastNumber[0] = 0;
        
        for (int i = 1; i <= amount; i++) {
            for (auto& j : coins) {
                int sub = i - j;
                if (sub >= 0 && leastNumber[sub] != INT_MAX) {
                    leastNumber[i] = min(leastNumber[i], leastNumber[sub] + 1);
                }
            } 
        }
        
        return leastNumber[amount] != INT_MAX ? leastNumber[amount] : -1;
    }
};