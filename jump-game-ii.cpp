class Solution {
public:
    int jump(vector<int>& nums) {
         vector<int> temp(nums.size(),0);
         int right = 0;
         for(int i=0; i<nums.size(); ++i){
             if(nums[i]+i>right){ //比最右侧大更新解
                for(int j=right+1; j<=i+nums[i]&&j<nums.size(); ++j){ //对上一次的右侧边界和新的右侧边界中间更新解
                     if(temp[j]==0)
                        temp[j] = temp[i]+1;
                 }
                 right = nums[i]+i;
             }
         }
         return temp[nums.size()-1];
    }
};