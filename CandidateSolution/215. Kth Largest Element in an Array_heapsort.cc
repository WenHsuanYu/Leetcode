//using heap sort method
//max heap
//sort the array in increasing order
//TC: O(nlogn)
//SC: O(1)
static int syn = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    
    void max_heapify(vector<int>& nums, int parent, int n){
        int largest = parent;
        int left_child = 2 * parent + 1;
        int right_child = 2 * parent + 2;
        if (left_child < n && nums[left_child] > nums[largest])
            largest = left_child;
        if (right_child < n && nums[right_child] > nums[largest])
            largest = right_child;
        if (largest != parent) {
            swap(nums[parent], nums[largest]);
            max_heapify(nums, largest, n);
        }
    }
    
    void heapsort(vector<int>& nums, int n) {
        for (int i = n / 2; i >= 0; i--) {
            max_heapify(nums, i, n);
        }
        for(int i = n - 1; i >= 0; i--) {
            swap(nums[i], nums[0]);
            max_heapify(nums, 0, i);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        heapsort(nums, n);
        return nums[n - k];
    }
};