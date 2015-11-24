class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(A==NULL||n==0){
            return NULL;
        }
        int p=1;
        for(int i=1;i<n;i++){
            if(A[i]!=A[i-1]){
                A[p++]=A[i];
            }
        }
        return p;
        
    }
};