class Solution {
public:
    int singleNumber(int A[], int n) {
        int b0 = 0,b1 = 0,reset = 0;
        for(int i=0;i<n;++i){
            b1|=b0&A[i];
            b0=b0^A[i];
            reset=b0&b1;
            b0=reset^b0;
            b1=reset^b1;
        }
        return b0;
    }
};