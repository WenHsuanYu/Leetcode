//using iterative method
//TC: O(n)
//SC: O(1)
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) (((a) > (b) ? (b) : (a)))

static auto i = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = -100000;
        int minValue = prices[0]; 
        for (int i = 1; i < n; i++) {
            maxProfit = max(maxProfit, prices[i] - minValue);
            minValue = min(prices[i], minValue);
        }
        return maxProfit > 0 ? maxProfit : 0;
    }
};