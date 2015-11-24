class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.size() <= 1) return nums;
        vector<int> res;
        int idx = 0, count = 1;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[idx] == nums[i])  ++count;
            else {
                if (count > nums.size() / 3) res.push_back(nums[idx]);
                count = 1;
                idx = i;
            }
        }
        if (count > nums.size() / 3) res.push_back(nums[idx]);
        return res;
    }
};