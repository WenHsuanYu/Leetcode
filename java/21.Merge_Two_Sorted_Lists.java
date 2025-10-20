// TC: O(m + n)
// SC: O(1)
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if (list1 == null || list2 == null)
            return list1 != null ? list1 : list2;
        
        ListNode res = new ListNode();
        ListNode it = res;
        while (list1 != null && list2 != null) {
            if (list1.val < list2.val) {
                it.next = list1;
                list1 = list1.next;
            } else {
                it.next = list2;
                list2 = list2.next;
            }
            it = it.next;
        }
        it.next = list1 != null ? list1 : list2;
        return res.next;
    }
}
