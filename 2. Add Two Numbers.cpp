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
    

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* result = nullptr;
        ListNode* curr = nullptr;
        int sum, carry = 0;
        
        while(l1 || l2 || carry > 0) {
            
            sum = 0;
            
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            sum += carry;
            ListNode *new_node = new ListNode(sum % 10);
            if(!result) {
                result = new_node;
            } else {          
                curr->next = new_node;
            }
            curr = new_node;
            
            carry = sum / 10;            
            
        }
        return result;
        
    }