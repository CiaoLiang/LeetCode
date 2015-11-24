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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)
            return NULL;
        ListNode* temp1 = new ListNode(-1);
        temp1->next = head;
        ListNode* pretemp1=temp1;
        while(temp1){
            ListNode* next = temp1->next;
            if(next!=NULL&&next->val==val){
                temp1->next = next->next;
                delete next;
            }
            if(temp1->next!=NULL&&temp1->next->val==val)
                continue;
            temp1 = temp1->next;
        }
        return pretemp1->next;
    }
};