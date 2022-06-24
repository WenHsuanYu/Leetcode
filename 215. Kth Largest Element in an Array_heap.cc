//Using max heap
//TC: O(nlogn)
//SC: O(n)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (auto &i: nums) {
            pq.push(i);
        }
        for (int i = 1; i < k; i++) {
            pq.pop();
        }
        
        return pq.top();
    }
    
};

//Using min heap
//TC: O(nlogk)
//SC: O(k)
/* class Solution {
*  public: 
*    int findKthLargest(vector<int>& nums, int k) {
*        priority_queue<int, vector<int>, greater<int>> pq;
*        for (auto &i: nums) {
*            pq.push(i);
*            if (pq.size() > k) {
*                q.pop();
*            }
*        }
*        
*        return pq.top();
*    }
*    
*  };
*/