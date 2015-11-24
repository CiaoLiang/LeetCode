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
    ListNode *partition(ListNode *head, int x) {
        ListNode *small = new ListNode(0);
        ListNode *large = new ListNode(0);
        ListNode *pre = head;
        ListNode *ret = small;
        ListNode *temp = large;
        if(head==NULL)
            return NULL;
        while(pre!=NULL){
            if(pre->val<x){
                small->next = new ListNode(pre->val);
                small = small->next;
            }
            else{
                large->next = new ListNode(pre->val);
                large = large->next;
            }
            pre=pre->next;
        }
        small->next = temp->next;
        delete temp;
        return ret->next;
    }
};