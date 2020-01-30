// O(n) time and O(1) space solution

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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode * ret = new ListNode(0);
        ret->next = head;
        
        // swap two nodes  
        ListNode * prev = ret;
        ListNode * p = prev->next;
        while(p!=NULL&&p->next!=NULL)
        {
            ListNode * ne = p->next;
            ListNode * temp = ne->next;
            prev->next = ne;
            ne->next = p;
            p->next = temp;
            prev = p;
            p = temp;
        }
        return ret->next;

    }
};
