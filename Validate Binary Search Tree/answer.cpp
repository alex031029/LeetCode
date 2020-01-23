// quite an amount of tricky cases
// like [2147483647], [1,1]

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
    // ceil and floor is to determine if the root->val is valid
    // the initial value is LONG_MIN and LONG_MAX
    // long type is to avoid overflow of floor or ceil
    bool helper(TreeNode* root, long floor, long ceil) {
        if(root == NULL)
        {
            return true;
        }
        if(floor>=root->val||ceil<=root->val)
            return false;
        return helper(root->left, floor, root->val)&&helper(root->right, root->val, ceil);

    }
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};
