// use stacks to store the nodes 

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
        stack<ListNode *> s1;
        stack<ListNode *> s2;
        for(ListNode * p = l1; p!= NULL;p = p->next)
        {
            s1.push(p);
        }
        for(ListNode * p = l2; p!= NULL; p = p->next)
        {
            s2.push(p);
        }
        stack<ListNode *> ret;
        ListNode * zero = new ListNode(0);
        int carrier = 0;
        while(1)
        {
            if(s1.empty()&&s2.empty())
                break;
            
            ListNode * p1 = zero;
            ListNode * p2 = zero;
            if(!s1.empty())
            {
                p1 = s1.top();
                s1.pop();
            }
            if(!s2.empty())
            {
                p2 = s2.top();
                s2.pop();
            }
            
            ListNode * temp = new ListNode((p1->val+p2->val+carrier)%10);
            carrier = (p1->val+p2->val+carrier)/10;
            ret.push(temp);
        }
        ListNode * p = zero;
        
        // do not forget the carrier!
        if(carrier>=1)
        {
            p->next = new ListNode(carrier);
            p = p->next;
        }
        while(!ret.empty())
        {
            p->next = ret.top();
            ret.pop();
            p = p->next;
        } 

        return zero->next;
    }
};
