// two pass solution

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL||head->next==NULL)
            return NULL;
        int cnt=0;
        for(ListNode* p = head;p!=NULL;p = p->next)
        {
            cnt++;
        }
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* ne = cur->next;
        // cout<<cnt<<n<<endl;
        for(int i=0;i<cnt-n;i++)
        {
            pre = cur;
            cur = ne;
            ne = ne->next;
        }
        // DO NOT forget the case that pre = NULL
        if(pre==NULL)
            return head->next;
        pre->next = ne;
        return head;

    }
};
