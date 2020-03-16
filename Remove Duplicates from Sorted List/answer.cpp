// easy

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode * p1=head;
        ListNode * p2=head;
        while(p1!=NULL)
        {
            while(p1!=NULL&&p1->val==p2->val)
                p1 = p1->next;
            if(p1==NULL)
                break;
            p2->next = p1;
            p2 = p1;
        }
        // do not forget to add NULL
        p2->next = NULL;
        return head;
    }
};
