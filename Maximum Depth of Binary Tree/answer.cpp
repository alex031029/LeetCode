// a recursive solution
// easy

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
    int helper(TreeNode* root, int d) 
    {
        if(root==NULL)
            return d;
        return max(helper(root->left, d+1),helper(root->right, d+1));
    }
    int maxDepth(TreeNode* root) {
        return helper(root, 0);
    }
};
