// interpreted from answer_O(nk).cpp

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    // this function reverese all nodes between head and tail 
    // head and tail are excluded
    public ListNode TotalReverse(ListNode head, ListNode tail)
    {
        if(tail == head||head == null)
        {
            return head;
        }
        ListNode ret = head.next;
        ListNode p = head.next;
        ListNode prev = tail;
        while(p!=tail)
        {
            ListNode ne = p.next;
            p.next = prev;
            prev = p;
            p = ne;
        }
        head.next = prev;
        return ret;
    }
    public ListNode ReverseKGroup(ListNode head, int k) {
        if(head == null||k==1)
            return head;

        ListNode ret = new ListNode(0);
        ret.next = head;
        ListNode prevGroup = ret;
        ListNode p = ret.next;
        int cnt = 0;
        
        // the condition cnt==k is required
        // otherwise the case n==k can fail
        while(p!=null||(cnt==k))
        {
            // when cnt == k, we reverse all nodes between prevGroup and p
            if(cnt==k)
            {
                // cout<<prevGroup->val<<p->val<<endl;
                prevGroup = TotalReverse(prevGroup, p);
                cnt = 0;
            }
            else
            {
                cnt++;
                p = p.next;
            }
        }
        return ret.next;
    }
}
