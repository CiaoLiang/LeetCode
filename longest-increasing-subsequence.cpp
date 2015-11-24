class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        vector<int> Dp(nums.size(),1);
        int max = 0;
        int ret = 1;
        for(int i=1;i<nums.size();++i){
            int temp = 1;
            for(int j=0; j<i; ++j){
                if(nums[i]>nums[j]){
                    temp = Dp[j]+1;
                }
                else{
                    temp = 1;
                }
                if(temp>max){
                    max = temp;
                }
            }
            Dp[i] = max;
            max = 0;
            temp = 0;
            if(Dp[i]>ret){
                ret = Dp[i];
            }
        }
        return ret;
    }
};