// TC: O(H + K), where H is a tree height
// SC: O(H)
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

        //vector<int> res;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while (curr || !st.empty()) {
            if(curr) {
                st.push(curr);
                curr = curr->left;
            } else {
                curr = st.top();
                k--;
                if (k == 0) {
                    return curr->val;
                }
                //res.push_back(curr->val);
                st.pop();
                curr = curr->right;
            }
        }
        return res[k - 1];
    }
};