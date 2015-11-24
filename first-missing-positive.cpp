class Solution {
public:
    int firstMissingPositive(vector<int>& nums) { //交换的方法
        int len = nums.size();
        for(int i=0; i<len; ++i){
            if(nums[i]==i+1)
                continue;
            while(nums[i]!=i+1&&nums[i]>0&&nums[i]<nums.size()&&nums[i]!=nums[nums[i]-1]){ //交换直到直到出现无效的i位
            //注意边界条件，和重复交换的情况
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        int i;
        for(i=0; i<len; ++i){ //找到第一个不匹配的数字
            if(nums[i]!=i+1)
                break;
        }
        return i+1;
    }
    void swap(int &a,int &b){
        int temp = a;
        a = b;
        b = temp;
    }
};