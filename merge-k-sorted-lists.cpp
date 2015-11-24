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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       return par(lists,0,lists.size()-1);
    }
    ListNode *par(vector<ListNode*>&lists,int start,int end){
        if(start==end){
            return lists[start];
        }
        if(start<end){
            int mid = (start+end)/2;
            ListNode *l1 = par(lists,start,mid);
            ListNode *l2 = par(lists,mid+1,end); //mergesort par
            return mergeList(l1,l2);
        }
        return nullptr;
    }
    ListNode* mergeList(ListNode* list1,ListNode *list2){
        ListNode *ret = new ListNode(-1);
        ListNode *pre= ret;
        while(list1!=nullptr||list2!=nullptr){
            int val1 = list1==nullptr?INT_MAX:list1->val;
            int val2 = list2==nullptr?INT_MAX:list2->val;
            if(val1<=val2){
                ret->next = list1;
                list1 = list1->next;
            }
            else{
                ret->next = list2;
                list2 = list2->next;
            }
            ret = ret->next;
        }
        return pre->next;
    }
};