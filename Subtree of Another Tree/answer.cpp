// use pre order traversal of the tree

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
    // calculate the pre-order string of a tree
    void preOrder(TreeNode * root, string& str)
    {
        // we also need to record NULL 
        if(root==NULL)
        {
            str.push_back('*');
            return;
        }
        // # is used as a delimiter
        str+="#"+to_string(root->val);
        preOrder(root->left, str);
        preOrder(root->right, str);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        string sPreOrder;
        string tPreOrder;
        preOrder(s, sPreOrder);
        preOrder(t, tPreOrder);
        
        // if tPreOrder is a subtring of sPreOrder
        // then return true
        if(sPreOrder.find(tPreOrder)<sPreOrder.size())
            return true;
        else
            return false;
    }
};
