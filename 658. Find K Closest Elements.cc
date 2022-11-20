// Using binary search and sliding window 
//O(log(n - k))
//O(1)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int r = arr.size() - k;
        int mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (x - arr[mid] > arr[mid + k] - x) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return vector<int>(arr.begin() + l, arr.begin() + l + k);
    }
};