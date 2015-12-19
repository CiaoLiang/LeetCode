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
    TreeNode* mistake1,*mistake2;
    TreeNode* pre;
public:
    void recoverTree(TreeNode* root) {
        recursion(root);
        if(mistake1!=nullptr && mistake2!=nullptr){
            int temp = mistake1->val;
            mistake1->val = mistake2->val;
            mistake2->val = temp;
        }
    }
    void recursion(TreeNode* root){
        if(root==NULL)
            return;
        if(root->left){
            recursion(root->left);
        }
        if(pre!=NULL){
            if(root->val<pre->val){ 
                //顺序是否错误,如果错误就是找到了一个错误点，特别注意相邻交换的情况，这时只有一个错误，交换相邻点即可
                if(mistake1==NULL){
                    mistake1 = pre;
                    mistake2 = root;
                }
                else
                    mistake2 = root;
            }
        }
        pre = root; //记录前一个子节点
        if(root->right){
            recursion(root->right); //中序遍历，对BST是排序
        }
    }
};