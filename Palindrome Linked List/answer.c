// the C++ compiler in this question is flawed
// it always returns an AddressSanitizer: Heap-use-after-free error
// thus I change to C version

// O(n) time and O(1) space solution
// it use a fast and slow pointer in the list 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){
    if(head==NULL||head->next==NULL)
        return true;
    
    // determine if the list has odd elements
    bool odd = true;
    
    struct ListNode * fast = head, * slow = head;
    while(fast->next!=NULL&&fast->next->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    if(fast->next!=NULL)
    {
        fast = fast->next;
        odd = false;
    }
    // printf("fast:%d\tslow:%d\n",fast->val,slow->val);

    // reverse the 2nd half of the list
    struct ListNode * prev = slow;
    struct ListNode * cur = prev->next;
    while(cur!=NULL)
    {
        struct ListNode * ne = cur->next;
        cur->next = prev;
        prev = cur;
        cur = ne;
    }
    
    struct ListNode * p1,* p2;
    
    // we need to set slow as slow-next if the list has even elements
    if(!odd)
        slow = slow->next;
    for(p1 = head, p2 = fast; p1!=slow;p1=p1->next,p2=p2->next)
    {
        // printf("%d\t%d\n",p1->val,p2->val);
        if(p1->val!=p2->val)
            return false;
    }
    return true;
}
