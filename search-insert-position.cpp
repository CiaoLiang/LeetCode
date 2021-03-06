class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int lo = 0;
        int hi = n-1;
        while(lo<=hi){
            int mid = lo +(hi-lo)/2;
            
            if(A[mid]<target){
                lo = mid+1;
            }
            else if(A[mid>target]){
                hi = mid-1;
            }
            else return mid;
        }
        return lo;
    }
};