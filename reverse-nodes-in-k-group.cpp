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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head==NULL||k==1)
            return head;
        ListNode *cur = head;
        ListNode *next = head;
        ListNode *pre = new ListNode(-1);
        pre->next = head;
        ListNode *ret = pre;
        int n = 0;
        while(cur){
            ++n;
            cur = cur->next;
        }
        while(n>=k){
            cur=pre->next;
            next=cur->next;
            for(int i=1;i<k;++i){
                cur->next=next->next;
                next->next=pre->next;
                pre->next=next;
                next=cur->next;
            }
            pre = cur;
            n = n-k;
        }
        return ret->next;
    }
};