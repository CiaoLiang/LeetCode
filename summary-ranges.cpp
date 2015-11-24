class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        string temp;
        if(nums.size()==0)
            return res;
        int start = nums[0];
        int end = nums[0];
        if(nums.size()==1){
            res.push_back(to_string(nums[0]));
            return res;
        }
        for(int i=1;i<nums.size();++i){
            if(nums[i]==end+1){
                end = nums[i];
            }
            if(nums[i]!=end||i==nums.size()-1){
                if(start==end){
                    temp = to_string(start);
                    res.push_back(temp);
                }
                else{
                    temp = to_string(start)+"->"+to_string(end);
                    res.push_back(temp);
                }
                temp.clear();
                end = nums[i];
                start = nums[i];
            }
        }
        if(nums[nums.size()-1]!=nums[nums.size()-2]+1)
             res.push_back(to_string(nums[nums.size()-1]));
        return res;
    }
};