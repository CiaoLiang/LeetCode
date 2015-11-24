class Solution {
public:
    int uniquePaths(int m, int n) {
       vector<int> b(n);
       vector<vector<int> > a(m,b);
       a[0][0]=1;
       int ret;
       for(int i=0;i<m;i++)
       {
           for(int j=0;j<n;j++)
           {
               if(i==0||j==0)
               {
                   a[i][j]=1;  //edge judgement
               }
               else
               a[i][j]=a[i-1][j]+a[i][j-1];
           }
       }
       return a[m-1][n-1];

    }
};