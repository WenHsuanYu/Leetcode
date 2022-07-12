// TC: O(n)
// SC: O(2^ceil(logn))
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                TreeNode* tree = q.front();
                q.pop();
                if (tree->left) {
                    q.push(tree->left);
                }
                if (tree->right) {
                    q.push(tree->right);
                }
                if (i == len - 1) {
                    ans.push_back(tree->val);
                }
            }
        }
        
        return ans;
            
    }
};