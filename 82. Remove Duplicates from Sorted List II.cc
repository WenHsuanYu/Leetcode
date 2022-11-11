// Using dummyNode and two pointers
// TC: O(n)
// SC: O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(101);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = head;
        while (curr) {
            if(curr->next && curr->val == curr->next->val) {
                while(curr->next && curr->val == cur->next->val) {
                    curr = curr->next;
                }
                curr = curr->next;
                prev->next = curr;
                
            }
            else {
                prev = prev->next;
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};