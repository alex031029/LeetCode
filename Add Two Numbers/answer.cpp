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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * p1 = l1;
        ListNode * p2 = l2;
        ListNode * ret = new ListNode(0);
        ListNode * root = ret;
        int carry = 0;
        for(;p1!=NULL||p2!=NULL;)
        {
            int temp = 0;
            if(p1!=NULL)
            {
                temp+= p1->val;
                p1=p1->next;
            }
            if(p2!=NULL)
            {
                
                temp+=p2->val;
                p2=p2->next;
            }
            ListNode * tempNode = new ListNode(temp%10+carry);
            carry = temp/10;
            ret->next = tempNode;
            ret = tempNode;
        }
        if(carry!=0)
        {
            ret->next = new ListNode(carry);
        }
        return root->next;
    }
};
