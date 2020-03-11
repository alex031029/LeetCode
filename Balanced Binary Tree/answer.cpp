// post order DFS traversal
// to obtain the height for all nodes
// if the difference of two children of any node is larger than 1, we set ret as false

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
    map<TreeNode*, pair<int,int>> heights;
    bool ret = true;
    void dfs(TreeNode* root)
    {
        if(!ret)
            return;
        if(root==NULL)
        {
            heights[root] = make_pair(0,0);
            return;
        }
        dfs(root->left);
        dfs(root->right);
        auto childHeight = [this](TreeNode* p){return max(heights[p].first, heights[p].second)+1;};
        heights[root] = make_pair(childHeight(root->left),childHeight(root->right));
        if(abs(heights[root].first-heights[root].second)>1)
            ret = false;
    }
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return ret;
    }
};
