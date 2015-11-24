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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ret;
        stack<TreeNode*> nodes;
        TreeNode *temp;
        if(root)
        {
            nodes.push(root);
            while(!nodes.empty())
            {
                temp = nodes.top();
                nodes.pop();
                if(temp->right)
                {
                    nodes.push(temp->right);
                }
                if(temp->left)
                {
                    nodes.push(temp->left);
                }
                ret.push_back(temp->val);
            }
            
        }
        return ret;
    }
}; 