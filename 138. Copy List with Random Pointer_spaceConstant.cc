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
        
        Node* curr = head;
        //Every original node owns a copied node and puts it behind itself.
        //only deal with "next" pointer part of "head" list.
        while (curr) {
            Node* t = new Node(curr->val);
            t->next = curr->next;
            curr->next = t;
            curr = t->next;
        }
        
        curr = head;
        //only deal with "random" pointer part of "head" list.
        while (curr) {
            if (curr->random){
                //curr->random->next: point to copied node
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        
        //Remove the redudant links
        Node* dummyNode = new Node(-1);
        Node* tail = dummyNode;
        curr = head;
        while (curr) {
            tail->next = curr->next;
            curr->next = curr->next->next;
            curr = curr->next;
            tail = tail->next;
        }
        return dummyNode->next;
    }
};