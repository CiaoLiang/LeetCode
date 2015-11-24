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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        if(root==NULL)
        return res;
        preoder(root,1,res);
        return res;
        
    }
    void preoder(TreeNode *root, int level ,vector<int> &res){
        if(root==NULL)
        return;
        if(res.size()<level)
            res.push_back(root->val);
        preoder(root->right,level+1,res);
        preoder(root->left,level+1,res);
    }
};