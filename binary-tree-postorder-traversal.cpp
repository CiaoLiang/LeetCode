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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        Recursive(root,ret);
        return ret;
    }
    void Recursive(TreeNode *root,vector<int>&ret){
        if(root==NULL)
            return;
        if(root->left)  Recursive(root->left,ret);
        if(root->right) Recursive(root->right,ret);
        ret.push_back(root->val);
    }
};