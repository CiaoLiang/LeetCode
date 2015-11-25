class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        recursion(nums,0,ret);
        return ret;
    }
    void recursion(vector<int> &nums,int index,vector<vector<int>> &ret){
        if(index == nums.size()-1){
            ret.push_back(nums);
            return;
        }
        for(int i=index; i<nums.size(); ++i){
            if(dupsolution(nums,index,i))
                continue;
            swap(nums[index],nums[i]);
            recursion(nums,index+1,ret);
            swap(nums[i],nums[index]);
        }
    }
    void swap(int &a,int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    bool dupsolution(vector<int> nums,int step,int end){
        for(int i=step; i<end; ++i){
            if(nums[i] == nums[end])
                return true;
        }
        return false;
    }
};