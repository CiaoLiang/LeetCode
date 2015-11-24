class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ret;
        int mingap = INT_MAX;
        for(int i=0;i<nums.size()-2;++i){
            int j = i+1;
            int k = nums.size()-1;
            while(j<k){
                if(abs(nums[i]+nums[j]+nums[k]-target)<mingap){
                    mingap = abs(nums[i]+nums[j]+nums[k]-target);
                    ret = nums[i]+nums[j]+nums[k];
                }
                if(nums[i]+nums[j]+nums[k]<target){
                    ++j;
                }
                else if(nums[i]+nums[j]+nums[k]>target){
                    --k;
                }
                else if(nums[i]+nums[j]+nums[k]==target){
                    return target;
                }
                
            }
        }
        return ret;
    }
};