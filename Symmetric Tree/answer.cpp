// recursive solution
// BFS solution with two queues is also feasible

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
    bool isMirror(TreeNode* p1, TreeNode * p2)
    {
        if(p1==NULL&&p2==NULL)
            return true;
        if(p1==NULL||p2==NULL)
            return false;
        if(p1->val!=p2->val)
            return false;
        return isMirror(p1->left, p2->right)&&isMirror(p2->left, p1->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return isMirror(root->left, root->right);
    }
};
