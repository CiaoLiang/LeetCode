class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if(m==0){
             for(int i = 0;i<n;++i){
             A[m+i]=B[i];
           }
        }
        if(n==0)
          return;
        for(int i = 0;i<m;++i){
            if(A[i]>B[0]){
                sweep(A[i],B[0]);
            }
            for(int j=0;j<n-1;++j){
              if(B[j]>B[j+1]){
                  sweep(B[j],B[j+1]);
              }
              else break;
            }
        }
        for(int i = 0;i<n;++i){
            A[m+i]=B[i];
        }
    }
    
    void sweep(int &a,int &b){
        int temp = a;
        a = b;
        b = temp;
    }
};