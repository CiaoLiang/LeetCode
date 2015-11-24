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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode* pre = new ListNode(-1);
        pre->next = head;
        ListNode* cur = head;
        ListNode* nex = head;
        while(cur->next){
            nex = cur->next;
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
        }
        return pre->next;
    }
};