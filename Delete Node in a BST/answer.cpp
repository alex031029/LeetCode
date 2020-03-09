// a recursive solution

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
            return root;
         
        // find the node p such that p->val = key
        // and its father node pre
        TreeNode * p = root;
        TreeNode * pre = p;
        while(p!=NULL&&p->val!=key)
        {
            pre = p;
            if(p->val<key)
                p = p->right;
            else
                p = p->left;
        }
        // no nodes has value of val
        if(p==NULL)
            return root;
            
        // trival case: the only node in the tree is p
        if(p==root&&p->left==NULL&&p->right==NULL)
            return NULL;
            
        // base case: p is a leaf node 
        if(p->left==NULL&&p->right==NULL)
        {
            if(pre->left==p)
                pre->left = NULL;
            else
                pre->right = NULL;
            return root;
        }
        
        // if p has right child
        if(p->right!=NULL)
        {
            // we find p2, the smallest value of p's right subtree
            TreeNode * p2 = p->right;
            while(p2->left!=NULL)
            {
                p2 = p2->left;
            }
            // recursively delete p2 and set p->val as p2->val
            // temp is to prevent from modifying p2->val;
            int temp = p2->val;
            deleteNode(p, temp);
            p->val = temp;
        }
        // if p has no right child, but has left child
        else if(p->left!=NULL)
        {
            TreeNode * p2 = p->left;
            while(p2->right!=NULL)
                p2 = p2->right;
            int temp = p2->val;
            deleteNode(p, temp);
            p->val = temp;
        }
        return root;
    }
};
