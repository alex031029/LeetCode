/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 
reverse some part of a linked list
1->2->3->4->5
m = 2, n = 4
1->4->3->2->5
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head, int m, int n) {
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
    ListNode * anchor = pre;
    ListNode * anchor2 = p;
    pre = p;
    p = p->next;
    i++;
    ListNode * ne;
    while(i++<n)
    {
        ne = p->next;
        p->next = pre;
        pre = p;
        p = ne;
    }   
    anchor->next = p;
    anchor2->next = ne;
    return head;
    }
};
