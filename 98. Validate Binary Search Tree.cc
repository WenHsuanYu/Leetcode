// Using recursive method
// TC: O(n)
// SC: O(n)
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
    bool validate(TreeNode* root, TreeNode* lo, TreeNode* hi) {
        if (root == nullptr)
            return true;
        if ((lo != nullptr && root->val <= lo->val)  || (hi != nullptr && root->val >= hi->val)) {
            return false;
        }
        return validate(root->right, root, hi) and validate(root->left, lo, root);   
    }
    
    bool isValidBST(TreeNode* root) {
        return validate(root, nullptr, nullptr);
    }
};