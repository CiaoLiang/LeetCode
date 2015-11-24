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
    bool isSymmetric(TreeNode *root) {
        if(root==NULL)
        return true;
        return process(root->left,root->right);
    }
    bool process(TreeNode *p,TreeNode *q){
        if(p==NULL&&q==NULL)
        return true;
        if((!p&&q)||(p&&!q))
        return false;
        if(p->val!=q->val)
        return false;
        else 
        return process(p->left,q->right)&&process(p->right,q->left);
    }
};