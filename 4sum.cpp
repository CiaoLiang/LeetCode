class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        int len = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<len-3;++i){
            if(i>0&&nums[i]==nums[i-1]) continue;//dup start
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;//no result
            if(nums[i]+nums[len-1]+nums[len-2]+nums[len-3]<target) continue;//at this start no result,go to next one,important
            for(int j=i+1;j<len-2;++j){//3 sum
                if(j>i+1&&nums[j]==nums[j-1]) continue;//dup start
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;//优化的关键
                if(nums[i]+nums[j]+nums[len-1]+nums[len-2]<target) continue; //优化的关键
                int left = j+1;
                int right = len-1;
                while(left<right){
                    if(nums[i]+nums[j]+nums[left]+nums[right]==target){
                        ret.push_back({nums[i],nums[j],nums[left],nums[right]});
                        ++left;
                        --right;
                        while(nums[left]==nums[left-1]&&nums[right]==nums[right+1]){ //重复子解
                            ++left;
                            --right;
                        }
                    }
                    else if(nums[i]+nums[j]+nums[left]+nums[right]<target){
                        ++left;
                        while(nums[left]==nums[left-1]){
                            ++left;
                        }
                    }
                    else if(nums[i]+nums[j]+nums[left]+nums[right]>target){
                        --right;
                        while(nums[right]==nums[right+1]){
                            --right;
                        }
                    }
                }
            }
        }
        return ret;
    }
};