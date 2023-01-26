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
        ListNode* dummy = new ListNode(-1, head);
        ListNode* curr = head;
        ListNode* prev = dummy;
        ListNode* RevHead = nullptr;
        ListNode* RevTail = nullptr;
        while (true) {
            ListNode* nextStart = curr;
            for (int i = 0; i < k; i++) {
                if (!nextStart) {
                    return dummy->next;
                }
                nextStart = nextStart->next;
            }
            RevHead = curr;
            RevTail = prev;
            while (RevHead != nextStart) {
                auto tmp = RevHead->next;
                RevHead->next = RevTail;
                RevTail = RevHead;
                RevHead = tmp;
            }
            curr->next = RevHead;
            prev->next = RevTail;
            prev = curr;
            curr = RevHead;
        }
    }
};