// a high space solution using a vector

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
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL)
            return;

        vector<ListNode*> deque;
        ListNode * p = head;
        while(p!=NULL)
        {
            deque.push_back(p);
            p = p->next;
        }
        int left=0, right = deque.size()-1;
        ListNode * pre = NULL;
        while(left<right)
        {
            if(pre!=NULL)
                pre->next = deque[left];
            deque[left]->next = deque[right];
            pre = deque[right];
            left++;
            right--;
        }
        if(left==right)
        {
            pre->next = deque[left];
            pre = deque[left];
        }
        pre->next = NULL;
    }
};
