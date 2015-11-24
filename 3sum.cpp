class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(),nums.end());
        int len = nums.size();
        const int target = 0;
        for(int i=0;i<len-2;++i){
            int j = i+1;
            int k = len-1;
            if(i>0&&nums[i]==nums[i-1]) continue;//子解
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==target){
                    ret.push_back({ nums[i],nums[j],nums[k] });
                    while(nums[j]==nums[j+1]&&nums[k]==nums[k-1]&&j<k){
                        j++;
                        k--;
                    }
                    j++;
                    k--;
                }
                else if(nums[i]+nums[j]+nums[k]<target){
                    while(nums[j]==nums[j+1]&&j<k) ++j;
                    ++j;
                }
                else if(nums[i]+nums[j]+nums[k]>target){
                    while(nums[k]==nums[k-1]&&j<k) --k;
                    --k;
                }
            }
        }
        return ret;
    }
};