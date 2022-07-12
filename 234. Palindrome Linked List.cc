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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;   
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // length of head is odd
        if (fast != nullptr)
            curr = curr->next;
        
        
        while (curr != nullptr) {
            if (curr->val != prev->val) 
                return false;
            prev = prev->next;
            curr = curr->next;
        }
        
        return true;
    }
};