// a recursive solution
// the time complexity is also O(n) due to the stack space of recursion
// the basic idea is that split the binary tree into two subtrees
// and connect all right nodes in the left subtree to the corresponding left nodes in the right trees
// then invoke the connect() function for both subtrees

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
        Node * left = root->left;
        Node * right = root->right;
        
        // connect two abjacent nodes of two subtrees
        while(left!=NULL)
        {
            left->next = right;
            left = left->right;
            right = right->left;
        }
        // recursive handle two subtrees
        connect(root->left);
        connect(root->right);
        return root;
    }
};
