// Using bottom-Up Merge approach
// TC: O(nlogk)
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        int k = lists.size();
        int interval = 1;
        while (interval < k) {
            for (int i = 0; i < k - interval; i += interval * 2) {
                lists[i] = Merge(lists[i], lists[i + interval]);
            }
            interval <<= 1;
        }
        return lists[0];
    }
    
private:
    ListNode* Merge(ListNode* l1, ListNode* l2) {
        ListNode dummyNode(0);
        ListNode* tail = &dummyNode;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
                tail = tail->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
                tail = tail->next;
            }
            
        }
        tail->next = l1 ? l1 : l2;
        return dummyNode.next;
    }
};