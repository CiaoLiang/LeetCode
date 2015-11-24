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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        Traversal(root,ret);
        return ret;
    }
    void Traversal(TreeNode *root,vector<int> &ret)
    {
        if(root==NULL)
        return;
        else{
            Traversal(root->left,ret);
            ret.push_back(root->val);
            Traversal(root->right,ret);
        }
    }
};