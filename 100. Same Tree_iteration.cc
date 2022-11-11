// Using iterative method
// TC: O(N)
// SC: O(N)

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(p);
        q2.push(q);
        while (q1.size() && q2.size()) {
            auto np = q1.front();
            auto nq = q2.front();
            q1.pop();
            q2.pop();
            if (np && nq) {
                if (np->val != nq->val) {
                    return false;
                } else {
                    q1.push(np->left);
                    q1.push(np->right);
                    q2.push(nq->left);
                    q2.push(nq->right);
                }
            } else if (np || nq) {
                return false;
            } 
        }
        return true;
    }
};