// search the tree in BFS manner using two queue
// this BFS search the right child first 
// this method has O(n) space complexity 

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        // q1 for odd layer
        // and q2 for even layer
        queue<Node*> q1;
        queue<Node*> q2;
        q1.push(root);
        // root->left->next=root->right;
        
        while(!q1.empty()||!q2.empty())
        {
            Node * prev = NULL;
            while(!q1.empty())
            {
                Node * temp = q1.front();
                // cout<<temp->val<<"\t";
                temp->next = prev;
                prev = temp;
                if(temp->right!=NULL)
                    q2.push(temp->right);
                if(temp->left!=NULL)
                    q2.push(temp->left);
                q1.pop();
            }
            // cout<<endl;
            prev = NULL;
            while(!q2.empty())
            {
                Node * temp = q2.front();
                // cout<<temp->val<<"\t";
                temp->next = prev;
                prev = temp;
                if(temp->right!=NULL)
                    q1.push(temp->right);
                if(temp->left!=NULL)
                    q1.push(temp->left);
                q2.pop();
            }
            // cout<<endl;
        }
        
        // cout<<root->next<<endl;
        // cout<<root->left->left->next->next->val<<endl;
        return root;
    }
};
