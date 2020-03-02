// recursive solution
// but it is a bit slow, and kind of time consuming

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
    // maxRootPath[p] contains path passing through p and root
    map<TreeNode*, int> maxRootPath;
    // maxNonRootPath[p] contains path does not passing through p
    map<TreeNode*, int> maxNoneRootPath;
    
    // returned value
    int ret = INT_MIN;
    void helper(TreeNode* p) {
        // node without child
        if(p->left==NULL&&p->right==NULL)
        {
            maxRootPath[p] = p->val;
            maxNoneRootPath[p] = p->val;
        }
        
        // node with only one child
        else if(p->left==NULL&&p->right!=NULL)
        {
            helper(p->right);
            // the path pasing through p
            maxRootPath[p] = maxRootPath[p->right]+p->val;
            // the path do not passing through p
            maxNoneRootPath[p] =  maxNoneRootPath[p->right];
        }
        else if(p->left!=NULL&&p->right==NULL)
        {
            helper(p->left);
            maxRootPath[p] = maxRootPath[p->left]+p->val;
            maxNoneRootPath[p] = maxNoneRootPath[p->left];
        }
        
        // node with two children
        else 
        {
            helper(p->left);
            helper(p->right);
            // the path from one of p's children, passing through p
            maxRootPath[p] = p->val+max(maxRootPath[p->left],maxRootPath[p->right]);
            
            // the path passing from one's child to other one
            maxNoneRootPath[p] = p->val + maxRootPath[p->left]+ maxRootPath[p->right];
        }
        
        // trivial cases where p's value is larger
        maxRootPath[p] = max(maxRootPath[p],p->val);
        maxNoneRootPath[p] = max(maxNoneRootPath[p], p->val);
        
        // update ret
        if(maxRootPath[p]>ret)
            ret = maxRootPath[p];
        if(maxNoneRootPath[p]>ret)
            ret = maxNoneRootPath[p];
        return;
    }
    
    int maxPathSum(TreeNode* root) {

        helper(root);
        return ret;
    }
};
