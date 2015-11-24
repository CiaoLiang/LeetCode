/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL)
            return NULL;
        map<RandomListNode*,RandomListNode*> m;
        RandomListNode* prehead = head;
        RandomListNode* ret = new RandomListNode(head->label);
        RandomListNode* pret = ret;
        while(head!=NULL){
            m[head] = ret;
            if(head->next!=NULL)
            ret->next = new RandomListNode(head->next->label);
            ret = ret->next;
            head = head->next;
        }
        while(prehead!=NULL){
            if(prehead->random==NULL){
                (m[prehead])->random==NULL;
            }
            else (m[prehead])->random = m[prehead->random];
            prehead = prehead->next;
        }
        return pret;
    }
};