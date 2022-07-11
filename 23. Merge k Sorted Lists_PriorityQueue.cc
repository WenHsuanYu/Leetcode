// Using priority_queue approach
// O(nlogk)
// O(n)
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
        if (lists.empty())
            return nullptr;
        
        auto comp = [&](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
        int n = lists.size();
        for (int i = 0; i < n; i++) {
            if (lists[i]) {
                pq.push(lists[i]);
            }
        }

        
        ListNode dummyNode(0);
        ListNode* tail = &dummyNode;
        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            tail->next = temp;
            tail = tail->next;
            if (temp->next)
            {
                pq.push(temp->next);
            }
        }
        
        tail->next = NULL;
        return dummyNode.next;
    }
    
};