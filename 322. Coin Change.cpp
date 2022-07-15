// TC: O(n * amount)
// SC: O(amount)
class Solution {
    
public:
    int coinChange(vector<int>& coins, int amount) {
        int leastNumber[amount+1];
        for(auto& i : leastNumber) 
            i = INT_MAX;
        leastNumber[0] = 0;
                
        for(int i = 1; i <= amount; i++){
            int minNumber = INT_MAX;
            for(auto& j : coins){
                int sub = i - j;
                if(sub >= 0 && leastNumber[sub] != INT_MAX){
                    minNumber = min(minNumber, leastNumber[sub] + 1);
                }
            }
            leastNumber[i] = minNumber;
        }
        return leastNumber[amount] == INT_MAX ? -1 : leastNumber[amount];
    }
};