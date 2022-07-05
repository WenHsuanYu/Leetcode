// Using O(1) space method without hash table
//TC: O(n)
//SC: O(1)
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
        
        Node* curr = head;
        
        while(curr) {
            Node* t = new Node(curr->val);
            t->next = curr->next;
            curr->next = t;
            curr = t->next;
        }
        curr = head;
        
        while (curr) {
            if(curr->random)
                //curr->random->next: point to copied node
                curr->next->random = curr->random->next;
            curr  = curr->next->next;
        }
        
        curr = head;
        Node* res = curr->next;
        while (curr) {
            Node* t = curr->next;
            curr->next = t->next;
            if (t->next)
                t->next = t->next->next;
            curr = curr->next;
        }
        return res;
        
        
    }
};