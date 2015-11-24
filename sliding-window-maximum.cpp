class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        if(nums.size()==0)
            return ret;
        for(int i=0 ; i<nums.size()-k+1 ; ++i){
            int max = nums[i];
            for(int j=0; j<k; ++j){
                if(nums[i+j]>max)
                    max = nums[i+j];
            }
            ret.push_back(max);
        }
        return ret;
    }
};