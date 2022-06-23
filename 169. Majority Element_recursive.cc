//using recursive method
//TC: O(nlogn)
//SC: O(logn)
class Solution {
public:
    
    int countInRange(vector<int>& nums, int target, int left, int right) {
        int count = 0;
        for (int i = left; i <= right; i++) {
            if (nums[i] == target) {
                count++;
            }
        }
        return count;
    }
    
    int recur(vector<int>& nums, int left, int right) {
        //base case
        if(left == right)
            return nums[left];
        int mid = left + (right - left) / 2;
        int localLeft_max = recur(nums, left, mid);
        int localRight_max = recur(nums, mid + 1, right);
        
        if (localLeft_max == localRight_max)
            return localLeft_max;
        int left_max = countInRange(nums, localLeft_max, left, right);
        int right_max = countInRange(nums, localRight_max, left, right);
        return left_max > right_max ? localLeft_max : localRight_max;
        
    }

    int majorityElement(vector<int>& nums) {
        return recur(nums, 0, nums.size() - 1);
    }
};