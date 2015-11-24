class Solution {
public:
vector<int> productExceptSelf(vector<int>& nums) {
    int pre = 1;
    vector<int> ret(nums.size());
    for(int i = nums.size() - 1; i >= 0; --i) {
        ret[i] = pre;
        pre *= nums[i];
    }
    pre = 1;
    for(int i = 0; i < nums.size(); ++i) {
        ret[i] *= pre;
        pre *= nums[i];
    }
    return ret;
}
};