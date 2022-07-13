// TC(logn)
// SC(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int result = -1;
        
        auto res = [&](string t){
            int l = 0;
            int r = nums.size() - 1;
            int mid;
            while (l <= r) {
                mid = l + ((r - l) >> 1);
                if (nums[mid] == target) {
                    result = mid; 
                    (t == "first") ? r = mid -1 : l = mid + 1;
                } else if (nums[mid] < target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
                
            }
                     
            return result;
        };

        return {res("first"), res("last")};
        
        
    }
};