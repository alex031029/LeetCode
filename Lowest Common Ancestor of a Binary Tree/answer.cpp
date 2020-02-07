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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // record the anecstor of each node 
        map<TreeNode *, TreeNode *> ancestor;
        ancestor[root] = NULL;
        queue<TreeNode *> que;
        que.push(root);
        int flag = 0;
        
        // BFS the tree to fill ancestor, until both p and q are visited
        while(!que.empty()&&flag<2)
        {
            TreeNode * temp = que.front();
            if(temp->left!=NULL)
            {
                ancestor[temp->left] = temp;
                que.push(temp->left);
                if(temp->left == p||temp->left==q)
                    flag++;
            }
            if(temp->right!=NULL)
            {
                ancestor[temp->right] = temp;
                que.push(temp->right);
                if(temp->right == p|| temp->right == q)
                    flag++;
            }
            
            que.pop(); 
            
        }
        
        // tracking all ancestors of nodes q and p from the root.
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        s1.push(p);
        s2.push(q);
        while(s1.top()!=root)
        {
            s1.push(ancestor[s1.top()]);
        }
        // cout<<"1"<<endl;
        while(s2.top()!=root)
        {
            // cout<<s2.top()->val<<endl;
            s2.push(ancestor[s2.top()]);
        }
        // cout<<"2"<<endl;
        TreeNode * ret;
        
        // return the answer when the top elements are different;
        while(!s1.empty()&&!s2.empty())
        {
            if(s1.top()==s2.top())
                ret = s1.top();
            else
                break;
            s1.pop();
            s2.pop();
        }
        return ret;
    }
};
