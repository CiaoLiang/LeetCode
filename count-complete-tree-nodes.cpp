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
    int countNodes(TreeNode* root){
        if(root==nullptr)
            return 0;
        TreeNode* lt = root;
        TreeNode* rt = root;
        int leftdepth = 0;
        int rightdepth = 0;
        while(lt){
            leftdepth++;
            lt = lt->left;
        }
        while(rt){
            rightdepth++;
            rt = rt->right;
        }
        if(leftdepth==rightdepth)
            return pow(2,leftdepth)-1;
        else
            return countNodes(root->left)+countNodes(root->right)+1;
    }
};