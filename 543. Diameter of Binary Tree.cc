// Using DFS method
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
private:
    int diameter = 0;
    int dfs(TreeNode* node) {
        if(!node) {
            return 0;
        }
        int left = dfs(node->left);
        int right = dfs(node->right);
        diameter = diameter < left + right ? left + right : diameter;
        return 1 +  (left > right ? left : right);
    } 
    
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return diameter;
            
    }
};