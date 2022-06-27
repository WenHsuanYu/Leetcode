//Using deque method
//TC:O(n)
//SC:O(k)
static auto it = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;

        for (int i = 0; i < n; i++) {
            //If i minus k equals dp.front, then the sliding window should move right by one position
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            //do not add equal sign because the same numbers will be possbile maximum in next round
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
            
            
        }
        return ans;
    }
};

//TLE
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        if (n == 1) {
            ans.push_back(nums[0]);
            return ans;
        }
        deque<int> dq;
        int max_val = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (i > k - 1) {
                if (dq.front() == max_val) {
                    dq.pop_front();
                    max_val = INT_MIN;
                    for (int i = 0; i < dq.size(); i++) {
                        max_val = max_val > dq[i] ? max_val : dq[i];
                    }
                } else {
                    dq.pop_front();
                }
            }
            dq.push_back(nums[i]);
            max_val = max_val > nums[i] ? max_val : nums[i];
            if (i >= k - 1) {
                ans.push_back(max_val);
            }
        }
        return ans;
    }
};