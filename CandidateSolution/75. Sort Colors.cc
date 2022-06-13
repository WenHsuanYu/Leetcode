class Solution {
public:
    
    //using shell sort
    //gap: 2 * floor[N/4] + 1
    void merge(vector<int>& nums, int left, int right) {
        int n = right - left + 1; 
        
        auto gap = [](int n){
            
            if (n <= 1)
                return 0; 
            return 2 * (int)(floor(n / 4.0)) + 1;
        };
        
        int j;
        for (int len = gap(n); len > 0; len = gap(len)) {
            for (int i = 0; i + len <= right; i++) {
                j = i + len;
                if (nums[i] > nums[j])
                    swap(nums[i], nums[j]);
            }
            
        }
    }
    //in-place merge sort algorithm
    //The worst case of Time complexity: O(n^(3/2) * logn)
    //It is not a one-pass algorithm, but it's only constant extra space. 
    void mergesort(vector<int>& nums, int left, int right) {
        
        if (left == right)
            return; 
        int mid = left + ((right - left) >> 2);
        mergesort(nums, left, mid);
        mergesort(nums, mid + 1, right);
        merge(nums, left, right);
        
    }
    
    
    void sortColors(vector<int>& nums) {
        
        mergesort(nums, 0, nums.size() - 1);
    }
};