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
    int sumNumbers(TreeNode *root) {
        if(root==NULL)
            return 0;
        vector<int> ret;
        dfs(root,ret,0);
        int sum;
        for(auto i=ret.begin();i!=ret.end();++i){
            sum+=*i;
        }
        return sum;
    }
    void dfs(TreeNode *root,vector<int> &temp,int num){
        num=10*num+root->val;
        if(root->right==NULL&&root->left==NULL)
         {   temp.push_back(num);
             return;             }
        if(root->right!=NULL)
        dfs(root->right,temp,num);
        if(root->left!=NULL)
        dfs(root->left,temp,num);
    }
};