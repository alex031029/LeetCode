// a O(n) time and O(1) space solution

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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return NULL;
        
        stack<ListNode*> st;

        ListNode * p = head;
        ListNode * prev = NULL;

        while(p!=NULL)
        {
            ListNode * ne = p->next;
            p->next = prev;
            prev = p;
            p = ne;
        }
        return prev;
    }
};
