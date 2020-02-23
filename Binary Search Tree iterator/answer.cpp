// O(1) time and O(h) space solution, where h is the height of tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    // the stack is for find the parent of a node 
    stack<TreeNode*> stk;
    
    // the helper input all nodes smaller than root-val
    void helper(TreeNode* root) 
    {
        while(root!=NULL)
        {
            stk.push(root);
            root = root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        helper(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode * ret = stk.top();
        stk.pop();
        // for a non-null right tree
        // we are going to find the smallest element of the tree
        if(ret->right!=NULL)
            helper(ret->right);
        // cout<<ret->val<<"\t"<<endl;
        return ret->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
