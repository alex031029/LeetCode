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
    int helper(TreeNode * root, int offset)
    {
        int rightSum = 0;
        int leftSum = 0;
        if(root->right!=NULL)
            rightSum = helper(root->right, offset);
        root->val = offset + root->val + rightSum;
        if(root->left!=NULL)
            leftSum = helper(root->left, root->val);
        return root->val+leftSum-offset;
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(root==NULL)
            return root;
        helper(root, 0);
        return root;
    }
};
