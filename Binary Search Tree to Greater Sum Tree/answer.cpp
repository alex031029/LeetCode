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

    // it returns the of all elements in the tree
    // offset is the delivered from the ancestor
    int helper(TreeNode * root, int offset)
    {
        int rightSum = 0;
        int leftSum = 0;
        
        // the right subtree 
        if(root->right!=NULL)
            rightSum = helper(root->right, offset);
        root->val = offset + root->val + rightSum;
        
        // the left subtree
        // the offset is root-val after modification
        if(root->left!=NULL)
            leftSum = helper(root->left, root->val);
            
        // the offset is deducte since root->val and leftSum contains a offset respectively
        return root->val+leftSum-offset;
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(root==NULL)
            return root;
        helper(root, 0);
        return root;
    }
};
