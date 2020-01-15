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
        map<Node*, Node*> hash;

        int i=0;
        for(Node * p = head; p!=NULL; p=p->next)
        {
            cout<< p->val<<endl;
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
            Node * r = p->random;
            if(r != NULL)
            {
                if(hash.find(r)!=hash.end())
                    temp->random = hash[r];
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
