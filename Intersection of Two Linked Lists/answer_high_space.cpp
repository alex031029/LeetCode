// an O(n) space and O(n+m) time solution
// using a map as hash function

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
        map<ListNode *, bool> hash;
        while(p1!=NULL)
        {
            hash[p1] = true;
            p1 = p1->next;
        }
        while(p2!=NULL)
        {
            if(hash.find(p2)!=hash.end())
                return p2;
            p2 = p2->next;
        }
        return NULL;
    }
};
