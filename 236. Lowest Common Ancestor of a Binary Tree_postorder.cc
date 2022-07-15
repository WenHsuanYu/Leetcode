// Using postorder traversal approach
// TC: O(n)
// SC: O(n)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path;
        vector<TreeNode*> path_p;
        vector<TreeNode*> path_q;
        TreeNode* lastVisited = nullptr;
        stack<TreeNode*> st;
        while (root || !st.empty()) {
            if (root) {
                st.push(root);
                path.push_back(root);
                root = root->left;
            } else {
                root = st.top();
                if (root->right && lastVisited != root->right) {
                    // return from left
                    // visit root of (sub)tree
                    root = root->right;
                } else {
                    // return from right
                    // root of (sub)tree
                    lastVisited = root;
                    if (root == p) {
                        path_p = path;
                    } else if (root == q) {
                        path_q = path;
                    }
                    st.pop();
                    path.pop_back();
                    root = nullptr;
                }
            }
            if (path_p.size() && path_q.size()) {
                break;
            }
        }
        
        int lenp = path_p.size();
        int lenq = path_q.size();
        int i = 0;
        while (i < lenp && i < lenq && path_p[i] == path_q[i]) {
            i++;
        }    
        return path_p[i - 1];
    }
};