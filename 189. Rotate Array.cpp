class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //more runtime
        if (nums.size() < 2)
            return;
        
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k -1);
        reverse(nums, k, nums.size() - 1);
    }
    inline void reverse(vector<int>& nums, int begin, int end) {
        while (begin < end) {
            swap(nums.at(begin), nums.at(end));
            begin++;
            end--;
        }
    }
    inline void swap(int& a, int& b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
};