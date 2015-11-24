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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *ret = new ListNode(0);
        ListNode *pre = ret;
        ListNode *temp = head;
        if(head==NULL)
        return NULL;
        while(temp)
        {
            if((temp->next==NULL)||(temp->val!=temp->next->val)) //be caution with the sequence(temp->next==NULL)must before the next because when temp->next==NULL we cannot compare val to the NULL
            {
                ListNode *node = new ListNode(temp->val);
                ret->next = node;
                ret = ret->next;
            }
            temp=temp->next;
        }
        return pre->next;
    }
};