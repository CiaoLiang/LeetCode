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
private: 
    vector<vector<int>> ret;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return ret;
        vector<int> temp;
        dfs(root,sum,temp);
        return ret;
    }
    void dfs(TreeNode* root,int sum,vector<int> temp){
        temp.push_back(root->val);
        if(root->val==sum&&root->right==NULL&&root->left==NULL)
            ret.push_back(temp);
        if(root->left)
            dfs(root->left,sum-(root->val),temp);
        if(root->right)
            dfs(root->right,sum-(root->val),temp);
    }
};