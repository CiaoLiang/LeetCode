class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int sum = m+n;
        if(sum&0x01)
        {
            return findkth(A,m,B,n,sum/2+1);
        }
        else 
        {
            return (findkth(A,m,B,n,sum/2)+findkth(A,m,B,n,sum/2+1))/2.0;
        }
    }
    
    double findkth(int A[],int m,int B[],int n,int k){ //recursive findkth
        
        if(m>n)
        return findkth(B,n,A,m,k);
        
        if(m==0)
        return B[k-1];
        
        if(k==1)
        return min(A[0],B[0]); //edge examination
        
        int pa = min(k/2,m);
        int pb = k-pa;
        
        if(A[pa-1]<B[pb-1])    //recursive findkth
        {
            return findkth(A+pa,m-pa,B,n,k-pa);
        }
        else if(A[pa-1]>B[pb-1])
        {
            return findkth(A,m,B+pb,n-pb,k-pb);
        }
        else if(A[pa-1]==B[pb-1])
        {
            return A[pa-1];//??
        }

    }
};