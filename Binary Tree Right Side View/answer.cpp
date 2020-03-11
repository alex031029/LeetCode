// BFS solution
// very intuitive


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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)
            return vector<int>{};
        // push the child from right to left,
        // making sure that the right side node is the first element of either queue
        queue<TreeNode*> even;
        queue<TreeNode*> odd;
        vector<int>ret;
        odd.push(root);
        while(!odd.empty()||!even.empty())
        {
            if(!odd.empty())
                ret.push_back(odd.front()->val);
            while(!odd.empty())
            {
                TreeNode * temp = odd.front();
                if(temp->right!=NULL)
                    even.push(temp->right);
                if(temp->left!=NULL)
                    even.push(temp->left);
                odd.pop();
            }
            if(!even.empty())
                ret.push_back(even.front()->val);
            while(!even.empty())
            {
                TreeNode * temp = even.front();
                if(temp->right!=NULL)
                    odd.push(temp->right);
                if(temp->left!=NULL)
                    odd.push(temp->left);
                even.pop();
             }
        }
        return ret;
    }
};
