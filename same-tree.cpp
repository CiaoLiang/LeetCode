/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode *p, struct TreeNode *q) {
     if(p==NULL&&q==NULL)
        return true;
        if(!p&&q||p&&!q||p->val!=q->val)
        return false;
        else
        {
        bool left = isSameTree(p->left,q->left);
        bool right = isSameTree(p->right,q->right);
        return left&right;
        }
}