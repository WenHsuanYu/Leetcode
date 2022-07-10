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
    int path_num = 0;
    int pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return 0;
        
        recur(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return path_num;
    }
private:
    void recur(TreeNode* root, long targetSum) {
        if (!root) {
            return;
        }
        
        
        if (root->val == targetSum) {
            path_num += 1;
        }
        
        recur(root->left, targetSum - root->val);
        recur(root->right, targetSum - root->val);
    }
    
    
};