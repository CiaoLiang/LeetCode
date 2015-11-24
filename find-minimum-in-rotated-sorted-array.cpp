class Solution {
public:
    int findMin(vector<int> &num) {
        int lo = 0;
        int hi = num.size()-1;
        while(lo<hi)
        {
            int mid = (lo+hi)/2;
            if(num[mid]<num[hi]){
                hi = mid;
            }
            if(num[mid]>num[hi]){
                lo = mid+1;
            }
        }
        return num[lo];
    }
};