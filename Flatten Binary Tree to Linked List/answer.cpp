// a pre-order traversal of the tree
// with the help of a vector to store the tree nodes
// in-place algorithm should be feasible, but hard to implement

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
    vector<TreeNode*> preorder;
    void dfs(TreeNode* root)
    {
        if(root==NULL)
            return;
        preorder.push_back(root);
        dfs(root->left);
        dfs(root->right);
    }
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        dfs(root);
        TreeNode * p = root;
        for(int i=1;i<preorder.size();i++)
        {
            p->right = preorder[i];
            p->left = NULL;
            p = p->right;
        }
        p->left = NULL;
        p->right = NULL;
    }
};
