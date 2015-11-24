/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL)
            return;
        TreeLinkNode *temp = root;
        TreeLinkNode *link ;
        while(temp->left)
        {
           link = temp;
           while(link)
           {
               link->left->next = link->right;
               if(link->next)
                   link->right->next = link->next->left;
               link = link->next;
           }
           temp = temp->left;   
        }
    }
};