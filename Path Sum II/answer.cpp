// a DFS solution
// but it turned out to be quite slow

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
    vector<vector<int>> ret;
    void dfs(TreeNode * root, int offset, vector<int> path)
    {
        if(root==NULL)
            return;
        offset += root->val;
        path.push_back(root->val);
        if(offset==sum&&root->left==NULL&&root->right==NULL)
        {
            ret.push_back(path);
            return;
        }
        dfs(root->left, offset, path);
        dfs(root->right, offset, path);
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return {};
        this->sum = sum;
        dfs(root, 0, vector<int>{});
        return ret;
    }
};
