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
public:
    int index;
    unordered_map<int, int> umap;
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        index = postorder.size() - 1;
        
        for (int i = 0; i <= index; i++) {
            umap[inorder[i]] = i;
        }
        
        return recur(postorder, 0, postorder.size() - 1, index);
    }     

  
    TreeNode* recur(vector<int>& postorder, int start, int end, int& index) {
         
        if (start > end) {
            return nullptr;
        }
        int root =  postorder[index--];
        TreeNode* node = new TreeNode(root);
        node->right = recur(postorder, umap[root] + 1, end, index);
        node->left = recur(postorder, start, umap[root] - 1, index);
    
        
        return node;
    }
    
};