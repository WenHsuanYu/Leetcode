// Using Heap method
// TC: O(nlogk)
// SC: O(N + k)
class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
        }
        
        auto comp = [&m](int n1, int n2){
            return m[n1] > m[n2];
        };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        
        for (pair<int, int> p : m) {
            pq.push(p.first);
            if(pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<int>top(k);
        for(int i = 0; i < k; i++) {
            top[i] = pq.top();
            pq.pop();
        }
        return top;
    }
};