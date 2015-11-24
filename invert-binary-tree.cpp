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
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr)
            return nullptr;
        stack<TreeNode*> stk;
        TreeNode *res = root;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* node = stk.top();
            stk.pop();
            if(node->left||node->right){
                TreeNode* temp = node->left;
                node->left = node->right;
                node->right = temp;
            }
            if(node->left)
                stk.push(node->left);
            if(node->right)
                stk.push(node->right);
        }
        return res;
    }
};