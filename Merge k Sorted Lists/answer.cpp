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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return NULL;
        ListNode * ret = new ListNode(0);
        ListNode * p = ret;
        
        // a comparator as the 3rd paramater of a priority queue
        auto comparator = [](const ListNode * n1, const ListNode * n2)->bool{
            return n1->val>n2->val;
        };

        // bool operator<(ListNode * n1, ListNode * n2) const
        // {
        //     return n1->val > n2->val;
        // }

        // to pass a lambda function int priority_queue
        // we need to use decltype(comparator) to pass the type of lambda function into the priority queue
        // and use the constructor function () to pass the comparator into the priority queue (i.e., heap in the program)
        priority_queue<ListNode*, vector<ListNode*>, decltype(comparator)> heap(comparator);
        
        // initialize the heap
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]!=NULL)
                heap.push(lists[i]);
        }
      
        while(!heap.empty())
        {
            ListNode * n = heap.top();
            heap.pop();
            if(n == NULL)
                continue;
            p->next = n;
            p = p->next;
            if(n->next!=NULL)
                heap.push(n->next);
        }
        return ret->next;
    }
};
