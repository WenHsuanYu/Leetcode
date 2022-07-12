// Using recursive approach
// TC: O(n)
// SC: O(n/k) = O(n)
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
        ListNode* next_start = head;
        for(int i = 0; i < k; i++) {
            if (!next_start) {
                return head;
            }
            next_start = next_start->next;
        }
        
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        for (int i = 0; i < k; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};