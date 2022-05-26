// Greedy algorithm
// starting from the second-last element and ending with the first element. (Top-down)

static auto last = []{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int last = n - 1;
        for (int i = n - 2; i >= 0; i--){
            if (i + nums[i] >= last){
                last = i;
            }
        }
        return last == 0;
    }
};