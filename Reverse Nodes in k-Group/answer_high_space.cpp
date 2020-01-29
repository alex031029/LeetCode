// a solution with O(k) space complexity
// the basic idea is to use a stack of k-size
// the time complexity is O(k*n) on average. 
// the worst case is O(n^2) and the best case is O(n)

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL||k==1)
            return head;
        int cnt = 0;
        ListNode * p = head;
        ListNode * ret = new ListNode(0);
        
        // the prev pointer is to record the node of the previous k-group
        // it is initialized as ret
        ListNode * prev = ret;
        prev->next = head;
        stack<ListNode*> st;
        while(p!=NULL)
        {
            // cout<<p->val<<" "<<cnt<<" "<<st.size()<<endl;
            // push the node
            st.push(p);
            p = p->next;
            cnt++;
            // for each k nodes, we pop all element in the stack and reverse them
            if(cnt%k==0)
            {
                cnt=0;
                ListNode * temp = st.top();
                prev->next = st.top();
                st.pop();
                while(!st.empty())
                {
                    temp->next = st.top();
                    temp = st.top();
                    st.pop();
                }
                temp->next = p;
                prev = temp;
            }
        }
        

        return ret->next;
    }
};
