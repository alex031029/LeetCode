// a recursive solution
// O(h) space required, where h is the heigh of the tree

// one thing is to find two swapped elements of a nearly increasing array
// we can one or two pairs of that are decreasing, 

// example1: 1432, two pairs, 43 and 32. 
// in the first pair, the previous element 4 is a swapped element
// in the second pair 32, the latter 2 is a swapped element.

// example2: 1324, only one pair 32.
// both elements are swapped 

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
    // x and y are two nodes need to be swapped 
    TreeNode * x;
    TreeNode * y;
    // previous node
    TreeNode * pre;
    void helper(TreeNode* root)
    {
        if(root==NULL)
            return;
        helper(root->left);
        
        // it is how we determine two swapped elements from a nearly increasing array
        if(pre!=NULL&&root->val<pre->val)
        {
            // cout<<pre->val<<"\t"<<root->val<<endl;
            if(x==NULL)
            {
                x = pre;
                y = root;
            }
            else
            {
                y = root;
                return;    
            }
        }
        pre = root;
        helper(root->right);
    }
    void recoverTree(TreeNode* root) {
        if(root==NULL)
            return;
        helper(root);
        swap(x->val,y->val);
    }
};
