// a java version of answr.cpp


/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode p1 = l1;
        ListNode p2 = l2;

        ListNode p = new ListNode(0);
        ListNode ret = p;

        // in Java, we use null, instead of NULL in C++
        // since we do have a pointer in java, we simply use a dot `.`,  and there is no ->
        while(p1!=null&&p2!=null)
        {
            if(p1.val<p2.val)
            {
                p.next = p1;
                p1 = p1.next;
            }
            else
            {
                p.next = p2;
                p2 = p2.next;
            }
            p = p.next;
        }
        if(p1==null)
        {
            p.next = p2;
        }
        else  
            p.next = p1;
        return ret.next;
    }
}
