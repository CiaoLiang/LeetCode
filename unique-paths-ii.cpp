class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rowlen = obstacleGrid.size();
        int colen = obstacleGrid[0].size();
        vector<vector<int>> Dp(rowlen,vector<int>(colen,0));
        for(int i=0; i<rowlen; ++i){
            if(obstacleGrid[i][0] == 1)
                break;
            Dp[i][0] = 1;
        }
        for(int i=0; i<colen; ++i){
            if(obstacleGrid[0][i] == 1)
                break;
            Dp[0][i] = 1;
        }
        for(int i=1; i<rowlen; ++i){
            for(int j=1; j<colen; ++j){
                if(obstacleGrid[i][j] == 1)
                    Dp[i][j] = 0;
                else Dp[i][j] = Dp[i-1][j]+Dp[i][j-1];
            }
        }
        return Dp[rowlen-1][colen-1];
    }
};