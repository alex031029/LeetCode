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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *p = new ListNode(0);
        // record the root;
        ListNode * ret = p;
        while(p1!=NULL&&p2!=NULL)
        {
            // ListNode * temp = new ListNode(0);
            if(p1->val<p2->val)
            {
                // te mp->val = p1->val;     
                p->next = p1;
                p1=p1->next;
            }
            else
            {
                // temp->val = p2->val;
                p->next = p2;
                p2=p2->next;
            }
            // p->next = temp;
            p = p->next;
        }
        if(p1==NULL)
        {
            p->next = p2;
        }
        else 
            p->next = p1;
        return ret->next;
    }
};
