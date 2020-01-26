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
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;

        ListNode * fast = head->next;
        ListNode * slow = head;

        while(1)
        {
            if(fast==slow)
                return true;
            if(fast==NULL||fast->next==NULL||slow==NULL)
                return false;
            slow = slow->next;
            fast = fast->next->next;
        }
    }
};
