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
    void deleteNode(ListNode* node) {
        if(node == nullptr)
            return;
        ListNode *next = node->next;
        node->val = node->next->val;
        node->next = next->next;
        delete next;
    }
};