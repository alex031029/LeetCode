// recursive solution

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
    int ret=0;
    void helper(TreeNode * root, int val)
    {
        // update ret when reaching a leaf node
        if(root->left==NULL&&root->right==NULL)
        {
            ret+=val*10+root->val;
            return;
        }
        
        // traverse left and right child
        if(root->left!=NULL)
            helper(root->left, root->val+val*10);
        if(root->right!=NULL)
            helper(root->right, root->val+val*10);
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
            return 0;
        helper(root, 0);
        return ret;
    }
};
