// an O(1) space solutoin


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
        Node * p = root;
        while(p!=NULL)
        {
            // this dummy served as a head node of each linked list of a level of the tree
            // it can be reused to satisfy O(1) space requirement
            Node * dummy = new Node(0);
            Node * tail = dummy;
            
            // using the next pointer to do a BFS traversal
            while(p!=NULL)
            {           
                if(p->left!=NULL)
                {
                    tail->next = p->left;
                    tail = tail->next;
                }
                if(p->right!=NULL)
                {
                    tail->next = p->right;
                    tail = tail->next;
                }
                p = p->next;
            }
            // go to the next level
            p = dummy->next;
        }

        return root;
        
    }
};
