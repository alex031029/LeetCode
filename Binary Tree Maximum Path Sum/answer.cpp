// recursive method
// same idea as answer_slow.cpp
// but it is much faster

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
    // record the result
    int ret = INT_MIN;
    int helper(TreeNode* p) {
        if(p==NULL)
            return 0;
        // the path from left child and right child
        int left = max(helper(p->left),0);
        int right = max(helper(p->right),0);
        
        // a path passing from p's two children
        int pathLeftToRight = p->val + left + right;
        
        // update the pass
        if(pathLeftToRight>ret)
            ret = pathLeftToRight;
        
        // return the pass to the root
        return p->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {

        helper(root);
        return ret;
    }
};
