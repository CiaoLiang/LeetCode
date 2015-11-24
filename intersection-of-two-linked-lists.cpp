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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      ListNode *LongList = headA;
      ListNode *ShortList = headB;
      unsigned int length1 = ListLength(headA);
      unsigned int length2 = ListLength(headB);
      int dif = length1-length2;
      
      if(length1<length2)
      {
          LongList = headB;
          ShortList = headA;
          dif = length2-length1;
      }
      
      for(int i=0;i<dif;++i)
      {
          LongList = LongList->next;
      }
 
      while((LongList!=NULL)&&(ShortList!=NULL)&&(LongList!=ShortList))
      {
          LongList = LongList->next;
          ShortList = ShortList->next;
      }
      if(LongList==NULL||ShortList==NULL)
      return NULL;
      ListNode *firstNode = LongList;
      return LongList;
    }
    
    unsigned int ListLength(ListNode *phead)
    {
        unsigned int nlength = 0;
        ListNode *pNode = phead;
        while(pNode!=NULL)
        {
            ++ nlength;
            pNode = pNode->next;
        }
        return nlength;
    }
};