// a recursive DFS solution

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
    int sum;
    bool ret = false;
    
    // offset represents the sum of the path
    void dfs(TreeNode * root, int offset)
    {
        if(root==NULL||ret)
            return;
        offset += root->val;
        if(offset==sum&&root->left==NULL&&root->right==NULL)
        {
            ret = true;
            return;
        }
        dfs(root->left, offset);
        dfs(root->right, offset);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return false;
        this->sum = sum;
        dfs(root, 0);
        return ret;
    }
};
