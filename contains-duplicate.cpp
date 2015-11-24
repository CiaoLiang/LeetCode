class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> Temp;
        for(int i=0;i<nums.size();++i){
            if(Temp.find(nums[i])!=Temp.end())
                return true;
            else
                Temp.insert(nums[i]);
        }
        return false;
    }
};