//Using Recursive method
//TC: O(n + m), where n is the number of nodes in list1 and m is the number of nodes in list2.
//SC: O(n + m), where n + m call times are stored on recursive call stack

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;   
        }
        if (list2 == nullptr) {
            return list1;
        }
        
        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
        
    }

};


