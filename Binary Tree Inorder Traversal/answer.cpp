// easy. a recursive solution

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
    vector<int> ret;
    void helper(TreeNode* root)
    {
        if(root->left!=NULL)
            helper(root->left);
        ret.push_back(root->val);
        if(root->right!=NULL)
            helper(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if(root!=NULL)
            helper(root);
        return ret;
    }
};
