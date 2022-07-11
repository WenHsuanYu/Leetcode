// Using hash table + queue approach (BFS)
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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode*> q;
        vector<int> vec;
        unordered_map<TreeNode*, int> um;
        q.push(root);
        int layer = 0;
        um[root] = layer;
        
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if (um[front] != layer) {
                ans.push_back(vec);
                vec.clear();
                layer++;
            }
            if (um[front] == layer) {
                vec.push_back(front->val);
            }
            if (front->left) {
                q.push(front->left);
                um[front->left] = layer + 1;
            }
            if (front->right) {
                q.push(front->right);
                um[front->right] = layer + 1;
            }
            
        }
        ans.push_back(vec);
        return ans;
        
    }
};