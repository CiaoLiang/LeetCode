class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int right = 0;
        int left = num.size()-1;
        while(right<left){
            int mid = (right+left)/2;
            if(num[mid]<num[mid+1]){
                right = mid+1;
            }
            else left = mid;
        }
        return right;
    }
};