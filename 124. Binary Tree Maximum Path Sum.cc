//TC: O(logn)
//SC: O(logn)
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
    
    
    int maxPath(TreeNode* root, int& MAX_path) {
        if (!root) {
            return 0;
        }
        int l = max(maxPath(root->left, MAX_path), 0);
        int r = max(maxPath(root->right, MAX_path), 0);
        int curr_max = root->val + l + r;
        MAX_path = max(MAX_path, root->val + l + r);
        return root->val + max(l, r);

    }
    
    
    int maxPathSum(TreeNode* root) {
        int MAX_path = INT_MIN;
        maxPath(root, MAX_path);
        return MAX_path;
    }
};