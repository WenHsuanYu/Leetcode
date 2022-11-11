// Using dummyNode and an extra pointer to dummyNode 
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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head || (head->next == nullptr && head->val == val))
            return nullptr;
        ListNode dummyNode(0);
        dummyNode.next = head;
        ListNode* ptr = &dummyNode;
        while (ptr->next) {
            if (ptr->next->val == val) {
                ptr->next = ptr->next->next;
            } else {
                ptr = ptr->next;
            }
        }
        return dummyNode.next;
    }
};