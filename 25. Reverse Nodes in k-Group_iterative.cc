// Using iterative approach
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* before_new_start = dummyNode;
        ListNode* new_start = head;
        ListNode* curr = nullptr;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;

        while(true) {
            ListNode* cursor = new_start;
            for (int i = 0; i < k; i++) {
                if (!cursor) {
                    return dummyNode->next;
                }
                cursor = cursor->next;
            }
            curr = new_start;
            prev = before_new_start;
            for (int i = 0; i < k; i++) {
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            
            new_start->next = curr;
            before_new_start->next = prev;
            before_new_start = new_start;
            new_start = curr;   
        }
    }
};