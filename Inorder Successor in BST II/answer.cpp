// two cases discussion 

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/
class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        Node * p = node;
        // if the right child exists
        if(p->right!=NULL)
        {            
            p = p->right;
            while(p->left!=NULL)
                p = p->left;
            return p;
        }
        // if the right child does not exist
        else
        {
            while(p->parent!=NULL&&p->val<=node->val)
            {
                p = p->parent;
            }
            // cout<<p->val<<endl;
            if(p->val>node->val)
                return p;
            else
                return NULL;
        }
    }
};
