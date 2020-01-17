/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// this solution is very slow, and consumes a lot of space
class Codec {
public:

    // Encodes a tree to a single string.

    string serialize(TreeNode* root) {
        if(root == NULL)
            return "";
        
        string ret;
        queue<TreeNode *> q;
        q.push(root);
        ret = to_string(root->val)+",";
        
        
        // the number 101 is served as null
        // it is just simpler to implemented when deserilized 
        // I was willing to use INT_MAX instead of 101
        // but INT_MAX would incur a out of space error
        auto NodetoString = [](TreeNode * n)->string{
            if(n == NULL)
                return to_string(-101)+",";
            else
                return to_string(n->val)+",";
        };

        while(!q.empty())
        {
            TreeNode * n = q.front();
            q.pop();
            ret = ret + NodetoString(n->left) + NodetoString(n->right);
            //cout<<ret<<endl;
            if(n->left!=NULL)
                q.push(n->left);
            if(n->right!=NULL)
                q.push(n->right);
        }
        // cout<<ret<<endl;
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == ""||data == to_string(-101)+",")
            return NULL;

        TreeNode * root = new TreeNode(0);
        int value = 0;
        
        // offset is to calculated how many characters have been read from sscanf
        // it is paired with %n to be used
        int offset = 0;
        sscanf(data.c_str(), "%d,%n", &value,&offset);
        root->val = value;
        TreeNode * p = root;
        queue<TreeNode *> q;
        q.push(root);
        while(1)
        {
            p = q.front();
            q.pop();
            int left, right, temp;
            if(sscanf(data.c_str()+offset, "%d,%d,%n", &left, &right, &temp)==EOF)
                break;
            offset+=temp;
            // cout<<left<<right<<endl;
            if(left== -101)
                p->left = NULL;
            else
            {
                p->left = new TreeNode(left);
                q.push(p->left);
            }
            if(right == -101)
                p->right = NULL;
            else
            {
                p->right = new TreeNode(right);
                q.push(p->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
