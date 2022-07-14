//using Divide and Conquer method
//TC: O(n)
//SC: O(n)

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
    int index;
public:

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        index = 0;
        unordered_map<int, int> umap;
        for (int i = 0; i < inorder.size(); ++i) {
            umap[inorder[i]] = i;
        }
        
        return recur(preorder, umap, 0, inorder.size() - 1, index);
        
    }
    //The range of indexs for subtree:[start, end]
    TreeNode* recur(vector<int>& preorder, unordered_map<int, int>& umap, int start, int end, int& index){
        if (start > end)
            return nullptr;
        TreeNode* node = new TreeNode(preorder[index]);
        int root = umap[preorder[index++]];
        node->left = recur(preorder, umap, start, root - 1, index);
        node->right = recur(preorder, umap, root + 1, end, index);
        
        return node;
        
        
    }
    
};


/* alternative implementation
 *
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 * class Solution {
 *     int index;
 * public:
 * 
 *     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
 *         index = 0;
 *         unordered_map<int, int> umap;
 *         for (int i = 0; i < inorder.size(); ++i) {
 *             umap[inorder[i]] = i;
 *         }
 *         
 *         function<TreeNode*(int, int)> it = [&](int start, int end) {
 *             if (start > end)
 *                 return (TreeNode*)nullptr;
 *             TreeNode* node = new TreeNode(preorder[index]);
 *             int root = umap[preorder[index++]];
 *             node->left = it(start, root - 1);
 *             node->right = it(root + 1, end);
 *             
 *             return node;
 *             
 *         };
 *         
 *         TreeNode* ans = it(0, inorder.size() - 1);
 *         return ans;
 *         
 *     }
 * };
**/


