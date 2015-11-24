class NumArray {
private:
    vector<int> a;
public:
    NumArray(vector<int> &nums) {
        int ret = 0;
        for(int i=0;i<nums.size();++i){
            ret += nums[i];
            a.push_back(ret);
        }
    }

    int sumRange(int i, int j) {
        return i==0?a[j]:a[j]-a[i-1];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);