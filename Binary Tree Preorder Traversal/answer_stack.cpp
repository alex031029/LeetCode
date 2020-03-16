// a non recursive implemenation via stack

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

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(root==NULL)
            return ret;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty())
        {
            TreeNode * p = stk.top();
            stk.pop();
            ret.push_back(p->val);
            if(p->right!=NULL)
                stk.push(p->right);
            if(p->left!=NULL)
                stk.push(p->left);
        }
        return ret;
    }
};
