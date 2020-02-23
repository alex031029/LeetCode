// a O(n) space solution

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
    int index = 0;

    vector<int> inorder;
    void helper(TreeNode* root)
    {
        if(root==NULL)
            return;
        helper(root->left);
        inorder.push_back(root->val);
        helper(root->right);
    }
    BSTIterator(TreeNode* root) {
        helper(root);
    }
    
    /** @return the next smallest number */
    int next() {
        return inorder[index++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return index<inorder.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
