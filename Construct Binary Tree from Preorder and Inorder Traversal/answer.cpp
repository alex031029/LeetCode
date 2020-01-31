// I use a recursive approach to handle this problem
// the basic idea is that, for each preorder, the first node must be the root
// and by utilizing inorder, we can find nodes for the left subtree and right subtree
// it call the function recursively to build the tree

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
        // the left tree 
        TreeNode * left = helper(preorder, l1+1, r1, inorder, l2, i-1);
        
        // the right tree. here l1+1+i-l2 indicates the index of the root of the right subtree
        // it is calculated as l1+1 (i.e., the root of left subtree) plus (i-l2) (i.e., the size of left tree)
        TreeNode * right = helper(preorder, l1+1+i-l2, r1, inorder, i+1, r2);
        root->left = left;
        root->right = right;
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};
