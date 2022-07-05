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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> umap;
        ListNode* ptr = headA;
        while (ptr) {
            umap[ptr] = ptr->val;
            ptr = ptr->next;
        }
        ptr = headB;
        while (ptr) {
            if (umap.find(ptr) != umap.end()) {
                return ptr;
            }
            ptr = ptr->next;
        }
        return nullptr;
    }
};