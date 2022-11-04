//Using iterative method
//TC: O(n)
//SC: O(n)
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next) {
            return nullptr;
        }
        ListNode* prev = head;
        ListNode* left = head;
        ListNode* right = head;
        while (right->next) {
            if (n == 1) {
                prev = left;
                left = left->next;
            } else {
                n--;
            }
            right = right->next;
        }
        // remove the first node
        if (prev == left)
            head = head->next;
        else {
            prev->next = prev->next->next;
        }
        return head;
    }
};