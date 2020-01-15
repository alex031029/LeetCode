/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;

        Node * ret = new Node(0);
        Node * p0 = ret;
        
        // a hash to determine if a Node has been created.
        map<Node*, Node*> hash;

        for(Node * p = head; p!=NULL; p=p->next)
        {
            // cout<< p->val<<endl;
            
            // create a Node if it has yet been created 
            Node * temp = NULL;
            if(hash.find(p)==hash.end())
            {
                temp = new Node(p->val);
                hash[p] = temp;
            }
            else
            {
                hash[p]->val = p->val;
                temp = hash[p];
            }
            
            // check the random pointer
            Node * r = p->random;
            if(r != NULL)
            {
                // if the random pointer is referring to a old Node 
                //  refer to it
                if(hash.find(r)!=hash.end())
                    temp->random = hash[r];
                // otherwise, create a new one and refer to it
                else
                {
                    Node * temp2 = new Node(r->val);
                    hash[r] = temp2;
                    temp->random = temp2;
                }
            }
            p0->next = temp;
            p0 = p0->next;
        }
        return ret->next;
    }
};
