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
        ListNode* cur = head;
        while (cur && cur->next) {
            ListNode* next_node = cur->next;
            if (cur->val == next_node->val) {
                cur->next = next_node->next;
                delete next_node;
            }
            else {
                cur = next_node;
            }
        }
        return head;
    }
};