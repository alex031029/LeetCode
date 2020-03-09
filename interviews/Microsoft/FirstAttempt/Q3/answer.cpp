struct Node 
{
    int val;
    Node * left;
    Node * right;
}

queue<bool> q;
bool helper(Node * root, Node * p)
{
    if(root==p) 
        return true;
    if(root->left!=NULL)
    {
        q.push(0)
        if(!helper(root->left,p))
            q.pop();
        else 
            return true;
    }
    if(root->right!=NULL)
    {
        q.push(1);
        if(!helper(root->right,p));
            q.pop();
        else 
            return true;
    }
    return false;
}
Node * mirrorNode(Node * root, Node * p)
{
    // trivial case where the tree has no node
    if(root==NULL)
        return NULL;
    // if(root==p)
    //    return p;
        
    if(!helper(root, p))
        return NULL;

    // the case p is not in the tree
    // if(q.empty())
    //    return NULL;
    
    Node * cur=root;
    while(!q.empty())  
    {
        if(cur==NULL)
            return NULL;
        // go opposite diretion from the root
        if(q.front())
        {
            cur = cur->left;
        }
        else
        {
            cur = cur->right;
        }
        q.pop();
    }
    return cur;
}


