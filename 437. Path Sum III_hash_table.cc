//Using hash table + recursive approach
//TC: O(n)
//SC: O(2^n) in worst case

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
    unordered_map<long, int> um;
    int ans = 0;
    void find(TreeNode* root, long sum, int& targetSum) {
        if (!root)
            return;
        sum += root->val;
        int prefixSum = sum - targetSum;
        if (um.find(prefixSum) != um.end()) {
            ans += um[prefixSum];
        }
        um[sum]++;
        find(root->left, sum, targetSum);  
        find(root->right, sum, targetSum);
        um[sum]--;
    }
    
    
    int pathSum(TreeNode* root, int targetSum) {
        um[0] = 1;
        find(root,  0, targetSum);
        return ans;
    }
};