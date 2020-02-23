// one pass solution
// using two pointers

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL||head->next==NULL)
            return NULL;
        int cnt=0;
        // the slow pointer is legging behind cur by n nodes
        // when cur is the last node, slow is referring the the previous node of the one we need to delete
        ListNode* cur = head;
        ListNode* slow = head;
        for(cur = head;cur->next!=NULL;cur = cur->next)
        {
            if(cnt++>=n)
                slow = slow->next;
        }
        // cout<<slow->val<<endl;
        if(cnt==n-1)
            return head->next;
        slow->next = slow->next->next;
        return head;

    }
};
