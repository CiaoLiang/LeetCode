class Solution {
public:
    int numSquares(int n) {
        vector<int> Dp(n+1);
        Dp[0] = 0;
        Dp[1] = 1;
        for(int i=1;i<n+1;++i){
            int sqrtindex = sqrt(i);
            Dp[i] = i;
            for(int j=1;j<sqrtindex+1;++j){
                if(Dp[i]>Dp[i-j*j]+1){
                    Dp[i] = Dp[i-j*j]+1;
                }
            }
        }
        return Dp[n];
    }
};