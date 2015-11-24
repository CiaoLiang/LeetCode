/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        if((root->left==NULL||Max(root->left)<root->val)&&(root->right==NULL||Min(root->right)>root->val))
            return isValidBST(root->left)&&isValidBST(root->right);
        else
            return false;
    }
    int Max(TreeNode *temp){
        if(temp->right==NULL)
            return temp->val;
        else return Max(temp->right);
    }
     int Min(TreeNode *temp){
        if(temp->left==NULL)
            return temp->val;
        else return Min(temp->left);
    }
};