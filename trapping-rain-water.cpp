class Solution {
public:
    int trap(int A[], int n) {
        int h = 0;
        int right = 0;
        int left = n-1;
        int area = 0;
        while(right<left){
            if(A[right]<A[left]){
                h = max(h,A[right]);
                area += h-A[right];
                ++right;
            }
            else
            {
                h = max(h,A[left]);
                area += h-A[left];
                --left;
            }
        }
       return area;
    }
};