class Solution{
public:
    int maxCoins(vector<int>& nums) {
        int nSize = nums.size()+2;
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> Dp(nSize,vector<int>(nSize,0));
        for(int k=3; k<=nSize; ++k){ //从不同长度的子解扩展开来
            for(int left=0; left<=nSize-k; ++left){//确定左右最后爆掉的气球
                int right = left+k-1;
                for(int i=left+1; i<right; ++i){//确定中间爆掉的
                    Dp[left][right] = max(Dp[left][right],nums[i]*nums[left]*nums[right]+Dp[left][i]+Dp[i][right]);
                    //Dp计算
                }
            }
        }
        return Dp[0][nSize-1];
    }
};