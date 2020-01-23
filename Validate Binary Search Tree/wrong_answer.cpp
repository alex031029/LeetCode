// it is a wrong code
// it cannot handle the case [10,5,15,null,null,6,20]
// whose correct answer is false
// it is because 6 is smaller than 10. 
// a binary tree requries all the nodes in its right branch is larger than the root node
// this code only consider its own right child,

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
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true;
        bool state1 = root->left==NULL||root->left->val<root->val;
        bool state2 = root->right==NULL||root->right->val>root->val;
        if(!state1||!state2)
            return false;
        return isValidBST(root->left)&&isValidBST(root->right);

    }
};
