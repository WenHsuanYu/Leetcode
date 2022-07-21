// Using dummyNode
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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !(head->next)) {
            return head;
        }
        
        ListNode dummyNode(0);
        dummyNode.next = head;
        ListNode* prev = &dummyNode;
        
        while (prev->next && head->next) {
            prev->next = head->next;
            head->next = head->next->next;
            prev->next->next = head;
            prev = head;
            head = head->next;
        }
        
        return dummyNode.next;
    }
};