// reverse a linked list

struct Node{
    int val;
    Node * next;
    Node(int x):val(x),next(NULL){};
    Node(int x, Node * ne):val(x),next(ne){};
};

Node * reverseLinkedList(Node * root)
{
    if(root==NULL||root->next==NULL)
        return root;
    Node * prev = NULL;
    Node * cur = root;
    while(cur!=NULL)
    {
        Node * ne = cur->next;
        cur->next = prev;
        prev = cur;
        cur = ne;
    }
    return prev;
}
