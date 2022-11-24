// TC: O(n)
// SC: O(1)
static auto out = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();


//Kadane's algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_max = 0;
        int ans = INT_MIN;
        for (auto i : nums) {
            curr_max += i;
            ans = max(ans, curr_max);
            curr_max = curr_max < 0 ? 0 : curr_max;
        }
        
        return ans;
    }
};