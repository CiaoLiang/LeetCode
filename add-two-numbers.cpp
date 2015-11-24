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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *result=new ListNode(0);
        ListNode *pre = new ListNode(0);
        result = pre; //location the head
        int number1 = 0;
        int number2 = 0;
        int c = 0 ;
        int temp = 0 ;
        while(l1!=NULL||l2!=NULL||c!=0)
        {
            number1=l1?l1->val:0;
            number2=l2?l2->val:0;
            temp = number1 + number2+c;
            c = temp/10;
            ListNode *Node=new ListNode(temp%10);
            pre->next = Node;
            pre = pre->next;
            l1 = (l1 == NULL)?NULL:l1->next;
            l2 = (l2 == NULL)?NULL:l2->next;
        } 
        return result->next;
    }
    
};