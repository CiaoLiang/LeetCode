class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    int hit = -1;
    int left=0, right=nums.size() - 1;
    int start = 0, end = 0;

    vector<int> ret(2, -1);

    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(nums[right] < target)    break;

        if(nums[mid] >= target)
        {
            if(nums[mid] == target) hit = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    if(hit == -1)   return ret;
    start = hit;

    left = hit;
    right = nums.size() - 1;
    hit = -1;

    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(nums[left] > target)    break;

        if(nums[mid] <= target)
        {
            if(nums[mid] == target) hit = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    if(hit == -1)   return ret;
    end = hit;

    ret[0] = start;
    ret[1] = end;

    return ret;
}
};