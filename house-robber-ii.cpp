class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        return max(RobLine(nums,0,nums.size()-1),RobLine(nums,1,nums.size()));
    }
    int RobLine(vector<int> &num,int start,int end ) {  
        if(num.size()==0)  
            return 0;  
        int step1=0;  
        int step2=0;  
        int step3=num[start];  
        int step4=0;  
        for(int i=start+1;i<end;++i){  
            step4=max(num[i]+step2,num[i-1]+step1);  
            step1=step2;  
            step2=step3;  
            step3=step4;  
        }  
        return step3;  
    }  
};