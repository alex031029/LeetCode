// it basic idea is similar to constructing a tree from preorder and inorder 
// by property of the binary search tree, we can determine the left subtree and right one

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
    TreeNode* helper(vector<int>& preorder, int l, int r)
    {
        if(r<l)
            return NULL;
        TreeNode * root = new TreeNode(preorder[l]);
        TreeNode * left = NULL;
        TreeNode * right = NULL;
        
        int pivot = l+1;
        for(;pivot<=r;pivot++)
        {
            if(preorder[pivot]>preorder[l])
                break;
        }
        
        left = helper(preorder, l+1, pivot-1);
        right = helper(preorder, pivot, r);
        root->left = left;
        root->right = right;
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, 0, preorder.size()-1);
    }
};
