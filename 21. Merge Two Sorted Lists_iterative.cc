//Using iterative method
//TC: O(m + n), where n is the number of nodes in list1 and m is the number of nodes in list2.
//SC: O(m + n)
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }
        
        ListNode* Merged_head = list1;
        if (list1->val <= list2->val) {
            list1 = list1->next;
        } else {
            Merged_head = list2;
            list2 = list2->next;
        }
        ListNode* Merged_tail = Merged_head;
        
        while (list1 && list2) {A
            if (list1->val < list2->val) {
                Merged_tail->next = list1;
                list1 = list1->next;
            } else {
                Merged_tail->next = list2;
                list2 = list2->next;
            }
            Merged_tail = Merged_tail->next;
        }
        //list1 is empty
        if (!list1) {
            Merged_tail->next = list2;
        } else {
            Merged_tail->next = list1;
        }
        
        
        return Merged_head;
    }
};