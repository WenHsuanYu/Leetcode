//Using hash table + recursive approach
//TC: O(n)
//SC: O(n) in worst case

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
    unordered_map<int64_t, int64_t> um;
    int ans = 0;
    void find(TreeNode* root, int64_t sum, int& targetSum) {
        if (!root)
            return;
        sum += root->val;
        //long prefixSum = sum - targetSum;
        if (um.find(sum - targetSum) != um.end()) {
            ans += um[sum - targetSum];
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