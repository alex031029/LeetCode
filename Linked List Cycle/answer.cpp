// An O(1) space solution
// the basic idea is to use two pointers, a fast one and a slow one
// the fast one moves two node for each iteration, 
// and the slow one moves only one node
// if these two pointers are referring to a same node at a certain time, it means the list has a cycle
// if the fast pointer refers to NULL, it means there is no cycle

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
