//using binary search method
//TC: O(logn)
//SC: O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n-1;
        if (n == 1)
            return nums[0];
        
        while(i <= j)
        {
            if(nums[i] < nums[j])
                return nums[i];
            int mid = i + (j - i) / 2;
            //circular prev and next
            int prev = (mid + n - 1) % n;
            int next = (mid + 1) % n;
           
            if(nums[mid] <= nums[prev] && nums[mid] <= nums[next])
                return nums[mid];
            if(nums[mid] >= nums[i])
                i = mid + 1;
            else if(nums[mid] <= nums[j])
                j = mid - 1;
          }
        return -1;
    }
};