// ericsson interview question

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL||n<=m)
            return head;
        ListNode * p =head;
        ListNode * pre = NULL;
        int i=1;
        for(;i<m;i++)
        {
            pre = p;
            p = p->next;
        }
        // cout<<p->val<<pre->val<<endl;
        // record two anchors
        ListNode * anchor = pre;
        ListNode * anchor2 = p;
        // cout<<anchor->val<<endl;
        // cout<<anchor2->val<<endl;
        pre = p;
        p = p->next;
        ListNode * ne;
        // reverse elements beteen m and n
        while(i++<n)
        {
            ne = p->next;
            p->next = pre;
            pre = p;
            p = ne;
        }   
        // cout<<pre->val<<endl;
        // cout<<p->val<<endl;
        // cout<<p->next->val<<endl;
        // check special case if m = 1
        if(anchor!=NULL)
            anchor->next = pre;
        else
            head = pre;
        anchor2->next = p;
        return head;
    }
};
