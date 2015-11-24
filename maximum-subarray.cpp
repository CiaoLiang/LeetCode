class Solution{
       public:
            int maxSubArray(int A[], int n)
            {
                 int res = A[0];
                 int temp = 0;
                 for(int i=0;i<n;i++)
                 {
                      temp = temp+A[i];

                      if(temp>res)
                           res = temp;

                      if(temp<0)
                           temp=0;

                 }
                 return res;
            }    

  };