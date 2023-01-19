//Using morris traversal algorithm
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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;
        TreeNode* pre;
        while (curr) {
            if (curr->left) {
                pre = curr->left;
                while (pre->right) {
                    pre = pre->right;
                }
                pre->right = curr;
                auto tmp = curr;
                curr = curr->left;
                tmp->left = nullptr;
            } else {
                if (!--k) {
                    return curr->val;
                }
                curr = curr->right;
            }
        }
        return -1;
    }
};