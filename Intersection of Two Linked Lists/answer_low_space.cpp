// an O(n+m) time and O(1) space solution
// we use two pointer to traverse the lists
// p1 traverses from headA, and shifts to headB when reaching NULL
// p2 shifts to headA hwne reaching NULL
// in this manner, two pointers are equally traverse list A+B, 
// and they will meet at some time if there has an intersecion
// if there is no intersection, p1 cannot meet p2 before reaching two NULL pointers

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL||headB == NULL)
            return NULL;
        if(headA==headB)
            return headA;
        
        ListNode * p1 = headA;
        ListNode * p2 = headB;
        int cnt = 0;
        while(1)
        {
            if(p1==p2)
                return p1;
            if(cnt>=2)
                return NULL;
            if(p1->next==NULL)
            {
                cnt++;
                p1 = headB;
            }
            else
                p1 = p1->next;
            if(p2->next==NULL)
                p2 = headA;
            else
                p2 = p2->next;

        }
        return NULL;
    }
};
