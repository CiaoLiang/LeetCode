class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> temp;
        for(int i=0;i<nums.size();++i){
            if(temp.find(nums[i])==temp.end()){
                temp[nums[i]] = i;
            }
            else{
                if(k>=(i-temp[nums[i]]))
                    return true;
            }
        }
        return false;
    }
};