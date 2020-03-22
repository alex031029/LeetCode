// a DFS solution
// I improved the dfs function to make it more efficient

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
    
    // use the reference of path to improve time efficiency
    void dfs(TreeNode * root, int offset, vector<int>& path)
    {
        if(root==NULL)
            return;
        offset += root->val;
        path.push_back(root->val);
        if(offset==sum&&root->left==NULL&&root->right==NULL)
        {
            ret.push_back(path);
            // do not forget to pop_back
            path.pop_back();
            return;
        }
        dfs(root->left, offset, path);
        dfs(root->right, offset, path);
        
        // do not forget to pop_back
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return {};
        this->sum = sum;
        
        // use the reference can improve the time efficiency by a large margin
        vector<int> path;
        dfs(root, 0, path);
        return ret;
    }
};
