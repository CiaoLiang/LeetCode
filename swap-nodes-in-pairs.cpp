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
    ListNode *swapPairs(ListNode *head) {
        ListNode *pre = new ListNode(0);
        pre->next = head;
        ListNode *ret = pre;
        if(head==NULL)
        return NULL;
        while(head!=NULL&&head->next!=NULL){
            pre->next = head->next;
            head->next = head->next->next;
            pre->next->next = head;
            pre = head;
            head = pre->next;
        }
        return ret->next;
    }
};