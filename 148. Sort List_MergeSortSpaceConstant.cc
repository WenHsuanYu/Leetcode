// Using merge sort (bottom-up) method
// TC: O(nlogn)
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next){
            return head;
        }
        
        ListNode dummyNode(0);
        dummyNode.next = head;
        
        int len = 1;
        while (head->next) {
            head = head->next;
            len++;
        }
        head = dummyNode.next;
        //represent points to the last node in merged linked list 
        ListNode* tail;
        ListNode* left;
        ListNode* right;
        ListNode* start;
        
        for (int step = 1; step <= len; step <<= 1) {
            //back to restart after updating step
            start = dummyNode.next;
            tail = &dummyNode;
            while (start) {
                left = start;
                right = split(left, step);
                //next time, where to start
                start = split(right, step);
                tail = merge(left, right, tail);
            }
        
        }
        return dummyNode.next;
        
    }
    
private:
    ListNode* split(ListNode* ptr, int len) {
        //move ptr to the last element in first linked list.
        for (int i = 1; ptr && i < len; i++) {
            ptr = ptr->next;
        }
        //The length is not enough to split
        if (!ptr) {
            return nullptr;
        }
        //Second linked list head
        ListNode* second_ptr = ptr->next;
        ptr->next = nullptr;
        return second_ptr;
    }
    
    ListNode* merge(ListNode* left, ListNode* right, ListNode* tail) {
        ListNode* curr = tail;
        while (left && right) {
            if (left->val <= right->val) {
                curr->next = left;
                left = left->next;
                curr = curr->next;
            } else {
                curr->next = right;
                right = right->next;
                curr = curr->next;
            }
        }
        curr->next = (left) ? left : right;
        //curr point to the last element in merged linked list
        while (curr->next) {
            curr = curr->next;
        }
        return curr;        
    }
    
};