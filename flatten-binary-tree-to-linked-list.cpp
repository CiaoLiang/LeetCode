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
    void flatten(TreeNode *root) {
        if(root==NULL)
            return;
        TreeNode* KeepRight = root->right;
        root->right = root->left;
        TreeNode* KeepLeft = root->left;
        TreeNode* pre = root;
        root->left = NULL;
        flatten(KeepLeft);
        while(pre->right!=NULL)
           pre = pre->right;
        pre->right = KeepRight;
        flatten(KeepRight);
    }
};