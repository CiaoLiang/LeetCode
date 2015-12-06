/*动态规划。f(i,j)代表 word1 前i位 和 word2 前 j位 转换时最小的次数。

分两种情况，如果word1[i] == word2 [j]:

i位和j位相等，说明 f(i,j) = f(i-1,j-1).没有cost

如果word1[i] 和 word2[j] 不相等，分三种情况：

删除  f(i-1,j) 替换 f(i-1,j-1)
插入 f(i,j-1) f(i,j) = min(f(i-1,j),f(i-1,j-1),f(i,j-1))+1；*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        if(len1==0)
            return len2;
        if(len2==0)
            return len1;
        vector<vector<int>> Dp (len1+1,vector<int>(len2+1,0)) ;
        for(int i=0; i<len1+1; ++i){
            Dp[i][0] = i;
        }
        for(int i=0; i<len2+1; ++i){
            Dp[0][i] = i;
        }
        for(int i=1; i<len1+1; ++i){
            for(int j=1; j<len2+1; ++j){
                if(word1[i-1] == word2[j-1]){
                    Dp[i][j] = Dp[i-1][j-1];
                }
                else{
                    Dp[i][j] = 1+min(Dp[i-1][j-1],Dp[i-1][j],Dp[i][j-1]);
                }
            }
        }
        return Dp[len1][len2];
    }
    int min(int a,int b, int c){
        int min = a;
        if(min>b)
            min = b;
        if(min>c)
            min = c;
        return min;
    }
};