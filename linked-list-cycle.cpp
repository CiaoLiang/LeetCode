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
    bool hasCycle(ListNode *head) {
        if(head==NULL)
        return false;
        ListNode *SlowPointer = head;
        ListNode *FastPointer = head->next; //forbide the first node equal
        while(FastPointer!=NULL&&FastPointer->next!=NULL)
        {
            if(FastPointer==SlowPointer)
            return true;
            SlowPointer = SlowPointer->next;
            FastPointer = FastPointer->next->next;
            
        }
        
    }
};