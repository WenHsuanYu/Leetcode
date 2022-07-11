// TC: O(n)
// SC: O(n)
class Solution {
public:
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans; 
        if (!root) 
            return ans;
        vector<int> vec;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int count = q.size();
            for (int i = 0; i < count; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                vec.push_back(node->val);
            }
            ans.push_back(vec);
            vec.clear();
        }
        return ans;
    }
};