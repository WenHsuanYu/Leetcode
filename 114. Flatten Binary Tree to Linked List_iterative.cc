//TC: O(n^2)
//SC: O(1)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *head = nullptr, *curr = root;
        while (head != root) {
            if (curr->right == head) {
                curr->right = nullptr;
            }
            
            if (curr->left == head) {
                curr->left = nullptr;
            }
            
            if (curr->right) { 
                curr = curr->right;
            }
            else if (curr->left) {
                curr = curr->left;
            }
            else {
                curr->right = head;
                head = curr;
                curr = root;
            }
        }
    }
};

//Using stack method
//TC: O(n)
//SC: O(ceil(logn)). When the program will run the leftmost leaves of the tree, the stack have the maximum number of elements at this point.
/*
* class Solution {
* public:
*     void flatten(TreeNode* root) {
*         if (!root)
*             return;
*         stack<TreeNode*> st;
*         st.push(root);
*         while(!st.empty()) {
*             TreeNode* cur = st.top();
*             st.pop();
*             if (cur->right) {
*                 st.push(cur->right);
*             }
*             if (cur->left) {
*                 st.push(cur->left);
*             }
*             if (!st.empty()) {
*                 cur->right = st.top();
*             }
*             cur->left = nullptr;
*         }
*     }
* };
*/