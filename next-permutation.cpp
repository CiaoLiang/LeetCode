class Solution {
//step1：从右往左找到第一个破坏升序(非严格)的元素，此例中为4.记下标为 i
//step2: 依然从右往左,找到第一个大于4的元素，此例中5，交换4和5.
//step3：从i+1到最右端，逆置。
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int temp = INT_MIN;
        int index = -1; //无升序
        for(int i=nums.size()-1; i>=0; --i){
            if(nums[i]<temp){ //非严格升序
                index = i;
                break;
            }
            temp = nums[i];
        }
        for(int i=nums.size()-1; i>=0; --i){
            if(index == -1) break; //严格升
            if(nums[i]>nums[index]){
                int temp = nums[i];
                nums[i] = nums[index];
                nums[index] = temp;
                break;
            }
        }
        swap(nums,index+1,len-1);
    }
    void swap(vector<int>& nums,int i,int j){
        while(i<j){
            int temp = nums[i];
            nums[i++] = nums[j];
            nums[j--] = temp;
        }
    }
};