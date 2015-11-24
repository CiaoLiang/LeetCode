/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private: 
    stack<TreeNode*> temp;
public:
    BSTIterator(TreeNode *root) {
       while(!temp.empty()){
           temp.pop();
       }
       
       while(root){
           temp.push(root);
           root=root->left;
       }
        
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !temp.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *ret = temp.top();
        TreeNode *subtree = ret->right;
        temp.pop();
        while(subtree){
            temp.push(subtree);
            subtree=subtree->left;
        }
        return ret->val;
        
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */