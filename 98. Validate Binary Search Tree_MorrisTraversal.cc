// TC: O(n)
// SC: O(1)

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
    bool isValidBST(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* prev = nullptr;
        TreeNode* last = nullptr; // the one before the current node
        bool find = true;
        while (curr) {
            if (curr->left == nullptr) {
                if (last && last->val >= curr->val) {
                    find = false;
                }
                    last = curr;
                    curr = curr->right;
            } else {
                prev = curr->left;
                while (prev->right) {
                    prev = prev->right;
                }
                
                prev->right = curr;
                auto temp = curr;
                curr = curr->left;
                temp->left = nullptr;
            }
        }
        return find;
    }
};