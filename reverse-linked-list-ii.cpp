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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(head==NULL||m==n)
          return head;
        ListNode *pre = new ListNode(-1);
        pre->next = head;
        ListNode *ret = pre;
        ListNode *cur = head;
        ListNode *nex = head;
        int t=n-m;
        while(m>1){
            pre=pre->next;
            cur=cur->next;
            --m;
        }
            nex = cur->next;
        while(t>0){
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
            --t;
        }
        return ret->next;
        
    }
};