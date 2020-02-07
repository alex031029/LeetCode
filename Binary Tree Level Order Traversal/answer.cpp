// use two queue for even and odd layers 
// the traverse the tree in BFS manner

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root == NULL)
            return ret;
        queue<TreeNode*> odd;
        queue<TreeNode*> even;
        odd.push(root);

        auto pushChildren = [](queue<TreeNode*>& que, TreeNode * t){
            if(t->left!=NULL)
                que.push(t->left);
            if(t->right!=NULL)
                que.push(t->right);
        };
        while(!odd.empty()||!even.empty())
        {
            vector<int> temp;
            while(!odd.empty())
            {
                pushChildren(even, odd.front());
                temp.push_back(odd.front()->val);
                odd.pop();
            }
            if(!temp.empty())
                ret.push_back(temp);
            temp.clear();
            while(!even.empty())
            {
                pushChildren(odd, even.front());
                temp.push_back(even.front()->val);
                even.pop();
            }
            if(!temp.empty())
                ret.push_back(temp);
        }
        return ret;
    }
};
