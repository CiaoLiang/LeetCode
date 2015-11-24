class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size()));
        int res = dp[0][0];
        for(int i=0;i<matrix.size();++i){
            dp[i][0] = matrix[i][0]-'0';
            if(dp[i][0]>res)
                res = dp[i][0];
        }
        for(int j=0;j<matrix[0].size();++j){
            dp[0][j] = matrix[0][j]-'0';
             if(dp[0][j]>res)
                res = dp[0][j];
        }
        for(int i=1;i<matrix.size();++i){
            for(int j=1;j<matrix[0].size();++j){
                if(matrix[i][j]=='0')
                    dp[i][j] = 0;
                if(matrix[i][j]=='1')
                    {
                        dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1;
                        if(dp[i][j]>res)
                            res = dp[i][j];
                    }
            }
        }
        return res*res;
    }
    int min(int a,int b,int c){
        if(a<=b&&a<=c)
            return a;
        if(b<=a&&b<=c)
            return b;
        if(c<=a&&c<=b)
            return c;
    }
};