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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr)
            return nullptr;
        ListNode* pre = new ListNode(0);
        ListNode* p1 = head;
        ListNode* p2 = head;
        int len = length(head);
        k = k%len;
        if(k%len == 0)
            return head;
            
        while(k!=0){
            p2 = p2->next;
            --k;
        }
        
        ListNode* first ; //the first rotate list
        while(p2->next!=nullptr){
                p1 = p1->next;
                p2 = p2->next;
        }
        
        first = p1->next;
        p1->next = nullptr;
        pre->next = first;
        p2->next = head;
        return first;
    }
    int length(ListNode *head){
        int k = 0;
        while(head!=nullptr){
            head = head->next;
            ++k;
        }
        return k;
    }
};