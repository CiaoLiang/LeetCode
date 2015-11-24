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
    int dfs(TreeNode *root)
    {
        if(root==NULL) return 0;
        else
        return max(dfs(root->left),dfs(root->right))+1;
    }
    void Ddfs(TreeNode *root,int t,vector<int> &vec,int step)
    {
        if(step==t) vec.push_back(root->val);
        if(root->left)  Ddfs(root->left,t,vec,step+1);
        if(root->right) Ddfs(root->right,t,vec,step+1);
    }
    vector<vector<int> > levelOrder(TreeNode *root) {
        int height=dfs(root);
        vector<vector<int> > vec1;
        for(int i=1;i<=height;i++)
        {
            vector<int> vec2;
            Ddfs(root,i,vec2,1);
            vec1.push_back(vec2);
        }
        return vec1;
    }
};