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
        // initialize a root with 0 value;
        ListNode * ret = new ListNode(0);
        ListNode * root = ret;
        int carry = 0;
        for(;p1!=NULL||p2!=NULL;)
        {
            int temp = 0;
            // add up from the smallest digit
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
            // the carry is taken into consideration
            ListNode * tempNode = new ListNode((temp+carry)%10);
            carry = (temp+carry)/10;
            ret->next = tempNode;
            ret = tempNode;
        }
        // add the highest digit of 1 if the carry is 1
        if(carry!=0)
        {
            ret->next = new ListNode(carry);
        }
        // the first node of root is useless, return the next node
        return root->next;
    }
};
