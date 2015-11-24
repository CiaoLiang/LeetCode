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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int min = p->val>q->val?q->val:p->val;
        int max = p->val>q->val?p->val:q->val;
        while(true){
            if(root->val>=min&&root->val<=max)
                break;
            if(root->val<min){
                root = root->right;
            }
            if(root->val>max){
                root = root->left;
            }
        }
        return root;
    }
};