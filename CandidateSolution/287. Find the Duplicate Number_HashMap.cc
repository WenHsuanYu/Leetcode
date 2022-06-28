//Using HashMap(Recursion) method
//TC: O(n)
//SC: O(n)
//Violating the constraint that the element cannot be modified
class Solution {
public:
    int recur(vector<int>& nums, int index) {
        if (index == nums[index])
            return index;
        int nxt = nums[index];
        nums[index] = index;
        return recur(nums, nxt);

    }
    
    
    int findDuplicate(vector<int>& nums) {
        return recur(nums, 0);
    }
};

//Using HashMap(Iterative) method
//TC: O(n)
//SC: O(1)
//Violating the constraint that the element cannot be modified

/*
* class Solution {
* public
*   int findDuplicate(vector<int>& nums) {
*       while (nums[0] != nums[nums[0]])
*           swap(nums[0], nums[nums[0]]);
*       return nums[0];
*   }
* };
*/