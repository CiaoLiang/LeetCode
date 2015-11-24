class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> temp;
        Search(ret,nums,temp,-1);
        return ret;
    }
    void Search(vector<vector<int>>&ret,vector<int> nums,vector<int> temp,int index){
        if(index>=0)
            nums.erase(nums.begin()+index,nums.begin()+index+1);
        if(nums.size()==0)
            ret.push_back(temp);
        for(int i=0; i<nums.size(); ++i){
            temp.push_back(nums[i]);
            Search(ret,nums,temp,i);
            temp.pop_back();
        }
    }
};