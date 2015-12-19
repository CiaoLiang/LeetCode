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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ret;
        if(n==0){
            return ret;
        }
        vector<vector<vector<TreeNode*>>> Dp(n,vector<vector<TreeNode*>>(n));//n*n 初始化Dp
        helper(1,n,ret,Dp);//开始Top－Down Dp，备忘录法递归
        return ret;
    }
    void helper(int start,int end,vector<TreeNode*> &ret,vector<vector<vector<TreeNode*>>> &Dp){
        if(start>end){
            ret.push_back(NULL);//start>end 没有解，放入NULL节点，递归终点，Dp初始值
            return;
        }
        if(!Dp[start-1][end-1].empty()){
            ret = Dp[start-1][end-1]; //把当前存储的Dp放在ret中，最后返回的ret就是Dp[0][n-1];
            return;
        }
        for(int i=start; i<=end; ++i){
            vector<TreeNode*> left; //左侧解集
            vector<TreeNode*> right;//右侧解集
            helper(start,i-1,left,Dp);
            helper(i+1,end,right,Dp);
            for(int j=0; j<left.size(); ++j){
                for(int k=0; k<right.size(); ++k){
                    TreeNode* node = new TreeNode(i);//Dp[0][n]就是遍历i从0到n,把i左指针指向左侧解集的每一个节点，右指针指向右侧解集的每一个节点
                    node->left = left[j];
                    node->right = right[k];
                    ret.push_back(node); //当前解放回ret
                }
            }
        }
        Dp[start-1][end-1] = ret;//保存Dp值
    }
};