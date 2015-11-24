class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int length = nums.size();
        int ret = nums.size()+1;
        int temp = 0;
        int start = 0;
        for(int i=0;i<length;++i){
            if(temp<s){
                temp += nums[i];
            }
            while(temp>=s){
                ret = (i-start+1)<ret?(i-start+1):ret;
                temp = temp - nums[start];
                start++;
            }
        }
        if(ret == nums.size()+1)
            return 0;
        return ret;
    }
};