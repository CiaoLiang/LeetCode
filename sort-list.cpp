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
    ListNode *sortList(ListNode *head) {
        if(head==NULL)
            return head;
        ListNode *start = head;
        ListNode *pre = head;
        vector<int> temp;
        while(start!=NULL){
            temp.push_back(start->val);
            start = start->next;
        }
        sort(temp.begin(),temp.end());
        int i = 0;
        while(head!=NULL){
            head->val=temp[i++];
            head=head->next;
        }
        return pre;
    }
};