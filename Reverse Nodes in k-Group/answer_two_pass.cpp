// An O(1) space solution
// but it is a two-pass method

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
    // this function reverese all nodes between head and tail 
    // head and tail are excluded
    ListNode * totalReverse(ListNode* head, ListNode * tail)
    {
        if(tail == head||head==NULL)
        {
            return head;
        }
        ListNode * ret = head->next;
        ListNode * p = head->next;
        ListNode * prev = tail;
        while(p!=tail)
        {
            ListNode * ne = p->next;
            p->next = prev;
            prev = p;
            p = ne;
        }
        head->next = prev;
        return ret;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL||k==1)
            return head;

        ListNode * ret = new ListNode(0);
        ret->next = head;
        ListNode * prevGroup= ret;
        ListNode * p = ret->next;
        int cnt = 0;
        
        // the condition cnt==k is required
        // otherwise the case n==k can fail
        while(p!=NULL||(cnt==k))
        {
            // when cnt == k, we reverse all nodes between prevGroup and p
            if(cnt==k)
            {
                // cout<<prevGroup->val<<p->val<<endl;
                prevGroup = totalReverse(prevGroup, p);
                cnt = 0;
            }
            else
            {
                cnt++;
                p = p->next;
            }
        }
        

        return ret->next;
    }
};
