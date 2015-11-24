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
    int kthSmallest(TreeNode* root, int k) {
        if(root==nullptr)
            return 0;
        vector<int> ret;
        recursive(root,ret);
        return ret[k-1];
    }
    void recursive(TreeNode* temp,vector<int> &ret){
        if(temp==nullptr)
            return;
        recursive(temp->left,ret);
        ret.push_back(temp->val);
        recursive(temp->right,ret);
    }
};