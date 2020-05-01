// a C# implementation
// incur O(1) extra space

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode MergeTwoLists(ListNode l1, ListNode l2) {
        ListNode ret = new ListNode(0);
        ListNode p = ret;
        while(l1!=null&&l2!=null)
        {
            if(l1.val<l2.val)
            {
                p.next = l1;
                l1 = l1.next;
            }
            else
            {
                p.next = l2;
                l2 = l2.next;
            }
            p = p.next;
        }
        if(l1 == null)
        {
            p.next = l2;
        }
        else
            p.next = l1;
        return ret.next;
    }
}
