//using Boyer-Moore Voting Algorithm
//TC: O(n)
//SC: O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        //Boyer-Moore Voting Algorithm
        int count = 0;
        int majority = 0;
        for (int i = 0; i < n; i++) {
            if (count == 0) {
                count ++;
                majority = nums[i]; 
            } else if (majority != nums[i]) {
                count--;
            } else {
                count++;
            }
        }
        return majority;
    }
};