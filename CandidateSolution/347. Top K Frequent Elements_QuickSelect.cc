//Using Quick select method
//Prevent worst case from happening, so I use random pivot
//TC: O(n) 
//SC: O(n)
class Solution {
public:
    //value of nums
    vector<int> value;
    // (value, frequency)
    map<int, int> mp;
    //pivot_index: index of vector<int> index
    int partition(int left, int right, int pivot_index) {
        int pivot_frequency = mp[value[pivot_index]];
        //let value[pivot_index] be a last element
        swap(value[right], value[pivot_index]);
        
        //point to a value whose frequency is less than pivot_frequency
        int count = left;
        for (int i = left; i <= right; i++) {
            if(mp[value[i]] < pivot_frequency) {
                swap(value[i], value[count]);
                count++;
            }
        }
        
        swap(value[count], value[right]);
        
        return count;
        
    }
    //k: N - k the most frequent element
    void  quickselect(int left, int right, int k) {
    
        while(true) {
            //only one element
            if (left == right)
                return;
            //random pivot
            int pivot_index = left + rand() % (right - left + 1);

            pivot_index = partition(left, right, pivot_index);
            if (k == pivot_index)
                return;
            else if (k > pivot_index)
                left = pivot_index + 1;
            else {
                right = pivot_index - 1;
            }
        }
        
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        for(int n: nums) {
            mp[n]++;
        }
        
        int n = mp.size();
        for (pair<int, int>p: mp) {
            value.push_back(p.first);
        }
        
        quickselect(0, n - 1, n - k);
        vector<int> top_k(value.begin() + (n - k), value.end());
        return top_k;
    }
};