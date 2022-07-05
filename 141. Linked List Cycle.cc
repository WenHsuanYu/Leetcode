//Using mark method
//TC: O(n)
//SC: O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        int index = 0;
        while (head) {
            if (head->val == -100001)
                return true;
            head->val = -100001;
            head = head->next;
        }
        return false;
    }
};


/*
* class Solution {
* public:
*     bool hasCycle(ListNode *head) {
*         if (!head) {
*             return false;
*         }
*         
*         if (head->next == nullptr) {
*             return false;
*         } 
*         ListNode* slow = head;
*         ListNode* fast = head;
*         while (fast->next != nullptr && fast->next->next != nullptr) {
*             slow = slow->next;
*             fast = fast->next->next;
*             if (slow == fast) {
*                 return true;
*             }
*         }
*         return false;
*         
*     }
* };
*/