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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return nodes(num,0,num.size()-1);
    }
    TreeNode *nodes(vector<int> &num, int begin ,int end)
    {
        int mid = (begin+end)/2;  //put the middle num in the root,then put the middle num in the left subtree,so do the right subtree.Recurse do this.
        if(begin>end)
        return NULL;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = nodes(num,begin,mid-1);
        root->right = nodes(num,mid+1,end);
        return root;
        
    }
};