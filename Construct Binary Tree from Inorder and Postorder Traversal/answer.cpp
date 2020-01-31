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
    TreeNode* helper(vector<int>& postorder, int l1, int r1, vector<int>& inorder, int l2, int r2)
    {
        if(l1>r1||l2>r2)
            return NULL;
        
        TreeNode * root = new TreeNode(postorder[r1]);
        int i = l2;
        for(i=l2;i<r2;i++)
        {
            if(inorder[i] == postorder[r1])
                break;
        }
        TreeNode * left = helper(postorder, l1, r1-1-(r2-i), inorder, l2, i-1);
        TreeNode * right = helper(postorder, l1, r1-1, inorder, i+1, r2);
        root->left = left;
        root->right = right;
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1);
    }
};
