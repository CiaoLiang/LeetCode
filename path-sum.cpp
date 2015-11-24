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
    bool hasPathSum(TreeNode *root, int sum) {
        if(root==NULL)
        return false;
        return value(root,sum,0);
    }
    bool value(TreeNode *root,int sum,int temp){
        if(root==NULL){
            if(temp==sum)
            return true;
            if(temp!=sum)
            return false;
        }
        temp = temp+(root->val);
        if(root->left==NULL)//&&root->right!=NULL)
        return value(root->right,sum,temp);
        if(root->right==NULL)//&&root->left!=NULL)
        return value(root->left,sum,temp);
        else
        return value(root->left,sum,temp)||value(root->right,sum,temp);
    }
};