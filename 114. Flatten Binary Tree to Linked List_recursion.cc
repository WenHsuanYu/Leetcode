// Using recursive method
//TC: O(n)
//SC: O(n)
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
    TreeNode* head = nullptr;
    //start at the Bottom and work up
    //recursively work down from right path to left path
    void reverse(TreeNode* curr) {
        if (curr->right) {
            reverse(curr->right);
        }
        if (curr->left) {
            reverse(curr->left);
        }
        curr->left = nullptr;
        curr-> right = head;
        head = curr;
    }
    
    
public:       
    void flatten(TreeNode* root) {
        if(root) 
            reverse(root);
    }
};