//using in-place mergesort method
//TC: O(nlogn) (best case)
//SC: O(1)
class Solution {
public:
    void merge(vector<int>& nums, int left, int middle, int j, int right, int work_area){
        while (left < middle && j < right) {
            nums[left] < nums[j] ? swap(nums[left++], nums[work_area++]) : swap(nums[j++], nums[work_area++]);  
        }
        while (left < middle) {
            swap(nums[left++], nums[work_area++]);
        }
        while (j < right) {
            swap(nums[j++], nums[work_area++]);
        }
    }

    void sort(vector<int>& nums, int left, int right, int work_area) {
        int middle;
        if (right - left > 1) {
            middle = left + ((right - left) > 1);
            imergesort(nums, left, middle);
            imergesort(nums, middle, right);
            merge(nums, left, middle, middle, right, work_area);
        } else {
            while (left < right) {
                swap(nums[left++], nums[work_area++]);
            }
        }
    }
    
    void imergesort(vector<int>& nums, int left, int right) {
        int middle, n, work_area;
        if (right - left > 1) {
            middle = left + ((right - left) >> 1);
            work_area = left + right - middle;
            //sort [left, middle) and put the result in the last half of nums
            sort(nums, left, middle, work_area); 
            while (work_area - left > 2) {
                n = work_area;
                work_area = left + (int)ceil((n - left) / 2.0);
                sort(nums, work_area, n, left);
                merge(nums, left, left + n - work_area, n, right, work_area);
            }            
            //insertion sort
            for (n = work_area; n > left; --n) {
                for (middle = n; middle < right && nums[middle] < nums[middle - 1]; ++middle) {
                    swap(nums[middle], nums[middle - 1]); 
                }
            }
            
        }
    }
    
    void sortColors(vector<int>& nums) {
        imergesort(nums, 0, nums.size());
    }
};


/**
* ------------------------------------------
*     unsorted       |       sorted
*    first half      |      last half
* ------------------------------------------
*
* ------------------------------------------
* sorted | unsorted  |      sorted
*   two quarters     |     last half
* ------------------------------------------
*
* ------------------------------------------
* unsorted   |      sorted
* one quarter|    three quarters
* ------------------------------------------
**/    
    