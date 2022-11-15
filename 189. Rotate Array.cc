// In the beginning, n is the length of nums and then becomes the remaining to be processed after running each for loop
// TC: O(n)
// SC: O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // if (nums.empty()) return;
        int n = nums.size();
        int start = 0;   
        // k %= n;
        while (n && (k %= n)) {
            // cout << "n: " << n << " k: " << k << endl;
            for (int i = 0; i < k; ++i) {
                swap(nums[i + start], nums[n - k + i + start]);
            }
            n -= k;
            start += k;
        }
    }
};

    