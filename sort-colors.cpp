class Solution {
public:
    void sortColors(int A[], int n) { //use three point , point right ,left,and curr
      int left = 0;
      int right = n-1;
      int curr = left;
      while(curr<=right){
          curr = (curr<=left)?left:curr;
          if(A[curr]==0){
              swap(A,left++,curr++);
          }
          else if(A[curr]==2){
              swap(A,right--,curr);
          }
          else{
              ++curr;
          }
      }
        
    }
    void swap(int A[],int a,int b){
        int temp = A[b];
        A[b] = A[a];
        A[a] = temp;
    }
};