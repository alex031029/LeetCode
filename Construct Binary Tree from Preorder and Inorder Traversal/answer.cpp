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
    TreeNode* helper(vector<int>& preorder, int l1, int r1, vector<int>& inorder, int l2, int r2)
    {
        if(l1>r1||l2>r2)
            return NULL;
        
        TreeNode * root = new TreeNode(preorder[l1]);
        int i = l2;
        for(i=l2;i<r2;i++)
        {
            if(inorder[i] == preorder[l1])
                break;
        }
        TreeNode * left = helper(preorder, l1+1, r1, inorder, l2, i-1);
        TreeNode * right = helper(preorder, l1+1+i-l2, r1, inorder, i+1, r2);
        root->left = left;
        root->right = right;
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};
