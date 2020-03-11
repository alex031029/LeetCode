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
    // set flag as true if p is traversed
    int flag = false;
    TreeNode * ret = NULL;
    
    // in order DFS
    void dfs(TreeNode * root, TreeNode * p)
    {
        if(root==NULL)
            return;
        dfs(root->left,p);
        if(flag)
        {
            // set ret if flag is true and ret is NULL
            if(ret==NULL)
                ret = root;
            return;
        }
        if(root==p)
            flag = true;
        dfs(root->right,p);
        
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        dfs(root, p);
        return ret;
    }
};
