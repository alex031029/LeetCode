/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
    vector<ListNode*> ret;
    // special case if root == NULL
    if(root==NULL)
    {
        for(int i=0;i<k;i++)    
            ret.push_back(NULL);
        return ret;
    }

    ListNode * p =root;

    // for(int i=0;i<k;i++)
    // {    
    //     ret.push_back(new ListNode(0));
    // }
    
    // calculated the size of the input list
    int len = 0;
    for(;p!=NULL;p=p->next)
    {
        len++;
    }
    // cout<<len<<endl;
    
    // a function to fastforward the pointer
    auto fastforward = [&](int t){
        for(int i=0;i<t;i++)
            p = p->next;
        // if(p!=NULL)
        //     cout<<p->val<<endl;
        // else 
        //     cout<<"NULL"<<endl;
    };

    // push back each pointer
    p = root;
    for(int i=0;i<k;i++)
    {
        ret.push_back(p);
        if(i<len%k)
        {
            fastforward(len/k);
        }
        else
            fastforward(len/k-1);
        ListNode * temp = p;
        if(p!=NULL)
        {
            p = p->next;
            temp->next = NULL;
        }
    }
    return ret;
    }
};
