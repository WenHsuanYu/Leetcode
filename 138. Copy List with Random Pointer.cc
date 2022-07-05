// Using iterative method
// TC: O(n)
// SC: O(n)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;
        
        Node* ptr = new Node(head->val);
        Node* res = new Node(0, ptr);
        unordered_map<Node*, Node*> um({{head, ptr}});
        while (head) {
            //next
            if (head->next == nullptr) {
                ptr->next = nullptr;
            } else if (um.count(head->next)){
                ptr->next = um[head->next];
            } else {
                ptr->next = new Node(head->next->val);
                um[head->next] = ptr->next;
            }
            //random
            if (head->random == nullptr) {
                ptr->random = nullptr;
            } else if (um.count(head->random)) {
                ptr->random = um[head->random];
            } else {
                ptr->random = new Node(head->random->val);
                um[head->random] = ptr->random;
            }
            head = head->next;
            ptr = ptr->next;
            
        }
        
        
        
        return res->next;
    }
};