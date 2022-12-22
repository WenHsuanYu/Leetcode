// TC: O(n)
// SC: O(1)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev = 0;
        int last = 0;
        for (const auto& val : cost) {
            int t = val + min(prev, last);
            prev = last;
            last = t;
        }
        return min(prev, last);
    }
};