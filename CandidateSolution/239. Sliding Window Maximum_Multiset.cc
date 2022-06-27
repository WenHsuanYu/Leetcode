//Using multiset method
//TC:O(nlogk)
//SC:O(k) => multiset has at most k elements. 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int> st;
        vector<int> ans; 
        for (int i = 0; i < n; i++) {
            if (i >= k)
                //O(logk)
                st.erase(st.find(nums[i - k]));
            //O(logk)
            st.insert(nums[i]);
            //Amortized constant
            if (i >= k - 1)
                ans.push_back(*(st.rbegin()));
        }
        return ans;
    }
};