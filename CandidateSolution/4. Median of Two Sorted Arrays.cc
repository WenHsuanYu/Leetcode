// An Interesting idea, but it does not meet the requirement of TC and it runs slowly in comparison with other solutions
// TC: O(max(m,n))
// SC: O(m + n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        // num1 和 num2 總數量的下半部分放入到 small 裡面
        priority_queue<int> small;
        // num1 和 num2 總數量的上半部分放入到 large 裡面，但是是以變成負數的方式放入
        // 如果相加節點總數量為偶數，那麼就是兩個 queue 相減(負數變正的相加)除二就是中位數
        // 如果相加節點總數量為奇術，我們將較多的節點維持在 small 那邊，所以 small 的頂端就是中位數
        priority_queue<int> large;
        int i = 0;
        int j = 0;
        while (i < len1 || j < len2) {
            if (i != len1) {
                small.push(nums1[i]);
                // 總是把在 small 中最大的負數化(negating)，也就是 small 頂端。
                large.push(-1 * small.top());
                //數字被放到 large，所以 small 要 pop out。
                small.pop();
                //檢查如果需要再平衡(維持 small 數量不小於 large)
                if (small.size() < large.size()) {
                    small.push(-1 * large.top());
                    large.pop();
                }
                i++;
            }
            if (j != len2) {
                small.push(nums2[j]);
                // 總是把在 small 中最大的負數化(negating)，也就是 small 頂端。
                large.push(-1 * small.top());
                //數字被放到 large，所以 small 要 pop out。
                small.pop();
                //檢查如果需要再平衡(維持 small 數量不小於 large)
                if (small.size() < large.size()) {
                    small.push(-1 * large.top());
                    large.pop();
                }
                j++;
            }
        }
        return small.size() > large.size() ? small.top() : (small.top() - large.top()) / 2.0;
        
    }
};