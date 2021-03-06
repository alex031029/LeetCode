// it is a solution using O(n) space 
// it utilizes a stack to store all nodes in the list

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
        ListNode * ret = new ListNode(0);

        ListNode * p = head;
        while(p!=NULL)
        {
            // cout<<p->val<<"\t";
            st.push(p);
            p = p->next;
        }
        p = ret;
        while(!st.empty())
        {
            // cout<<st.top()->val<<"\t";
            p->next = st.top();
            p = p->next;
            st.pop();
        }
        
        // do not forget to add a NULL at the end
        p->next = NULL;
        return ret->next;
    }
};
