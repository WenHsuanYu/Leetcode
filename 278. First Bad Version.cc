//TC: O(n)
//SC: O(1)

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n == 1) {
            return 1;
        }
        int ans = -1;
        int l = 1;
        int r = n;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (!isBadVersion(m)) {
                l = m + 1;
            } else {
                r = m;
                ans = m;
            }   
        }
        if (l == n && isBadVersion(l)) {
            ans = l;
        }
        
        return ans;
    }
};

