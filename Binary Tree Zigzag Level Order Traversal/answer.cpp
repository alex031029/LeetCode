// this solution use two stacks, oddLevel and evenLevel
// for odd levels, each node pushes its left child first
// for even levels, each noe pushes it right child first


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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    
        // two stacks for odd and even levels of the tree
        stack<TreeNode*> oddLevel;
        stack<TreeNode*> evenLevel;

        vector<vector<int>> ret;

        if(root==NULL)
            return ret;
        oddLevel.push(root);
        
        // loop until both stacks empty
        while(!oddLevel.empty()||!evenLevel.empty())
        {
            vector<int> temp;
            // the odd level pushes its left child first
            while(!oddLevel.empty())
            {
                TreeNode * p = oddLevel.top();
                if(p!=NULL)
                {
                    temp.push_back(p->val);
                    evenLevel.push(p->left);
                    evenLevel.push(p->right);
                }
                oddLevel.pop();
            }
            if(!temp.empty())
            ret.push_back(temp);
            temp.clear();
            
            // the even level pushes its right child first
            while(!evenLevel.empty())
            {
                TreeNode * p = evenLevel.top();
                if(p!=NULL)
                {
                    temp.push_back(p->val);
                    oddLevel.push(p->right);
                    oddLevel.push(p->left);
                }
                evenLevel.pop();
            }
            if(!temp.empty())
            ret.push_back(temp);
        }
        return ret;
        
    }
};
