/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return new TreeNode(head->val);
        ListNode *mid = head->next;
        ListNode *pre = head;
        int n = (length(head))/2;
        while(n>1){
            mid = mid->next;
            pre = pre ->next;
            --n;
        }
        TreeNode *root = new TreeNode(mid->val);
        root->right = sortedListToBST(mid->next);
        mid->next = NULL;
        pre->next = NULL;
        root->left = sortedListToBST(head);
        
    }
    int length(ListNode *pre){
        int n = 0;
        while(pre!=NULL){
            ++n;
            pre=pre->next;
        }
        return n;
    }
};