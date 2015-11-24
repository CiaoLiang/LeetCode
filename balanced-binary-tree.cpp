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
private: 
    bool balance = true;
    int treeHeight(TreeNode *root){
        if(balance!=true)
        {
            return -1;
        }
        if(root == NULL)
        {
            return 0;
        }
        int hl = treeHeight(root->left)+1;
        int hr = treeHeight(root->right)+1;
        if(abs(hl-hr)>1)
        {
            balance = false;
        }
        return hl>hr?hl:hr;
    }
public:
    bool isBalanced(TreeNode *root) {
        balance = true;
        treeHeight(root);
        return balance;
    }
};