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
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        TreeNode* ret;
        FindPath(root,path1,p);
        FindPath(root,path2,q);
        for(int i=0 ;i<min(path1.size(),path2.size());++i){
            if(path1[i]==path2[i])
                ret = path1[i];
        }
        return ret;
    }
    bool FindPath(TreeNode *root,vector<TreeNode*> &path,TreeNode *find){
        if(root == nullptr)
            return false;
        if(root == find){
            path.push_back(find);
            return true;
        }
        path.push_back(root);
        bool found = false;
        if(!found)
        found = FindPath(root->left,path,find);
        if(!found)
        found = FindPath(root->right,path,find);
        if(!found)
            path.pop_back();
        return found;
    }
};