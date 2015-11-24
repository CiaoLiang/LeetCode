class Solution {
public:
    int singleNumber(int A[], int n) {//use ^  single one = A[0]^A[1]^A[2]....^A[n-1];
       int ret=0;
       for(int i=0;i<n;i++){
           ret^=A[i];
       }
       return ret;
        
    }
};