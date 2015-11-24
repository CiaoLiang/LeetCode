class Solution {
public:
    bool canJump(int A[], int n) {
        
        int dest = n-1;
        int currpos = n-2;
        
        while(currpos>=0&&dest!=0){
            
            if(A[currpos]+currpos>=dest){
                
                dest = currpos;
                
            }
            --currpos;
        }
        
        return (dest==0)?true:false;
     
        }
        
};