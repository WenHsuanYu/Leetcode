// Using Morris Traversal (Threaded Binary tree) method
//TC: O(n)
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) {
            return ans;
        }
        
        TreeNode* curr = root;
        TreeNode* pre;
        while (curr) {
            if (!curr->left) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                pre = curr->left;
                //Do not check if there is a cycle (pre->right == curr) because the property of tree can not have a cycle
                while (pre->right) {
                    pre = pre->right;
                }
                pre->right = curr;
                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = nullptr;
                
            }
        
        }
        return ans;
        
    }
};