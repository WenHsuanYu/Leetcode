//TC: O(n)
//SC: O(1)

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
        
        ListNode* node = head;
        ListNode* temp;
        head = head->next;
        
        while (node && node->next) {
            temp = node->next->next;
            node->next->next = node;
            node->next = temp;
            if (node->next && node->next->next) {
                node->next = node->next->next;
            }
            node = temp;
        }
        
        return head;
    }
};