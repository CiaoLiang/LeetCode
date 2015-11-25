class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.length();
        int plen = p.length();
        vector<vector<bool>> Dp(slen+1,vector<bool>(plen+1));//2维DP表
        Dp[slen][plen] = true;
        for(int i=plen-1; i>=0; --i){
            if(p[i]!='*')
                break;
            else
                Dp[slen][i] = true;
        } //初始化解
        for(int i=slen-1; i>=0; --i){
            for(int j=plen-1; j>=0; --j){
                if(p[j]=='?'||p[j]==s[i]){
                    Dp[i][j] = Dp[i+1][j+1];
                }
                else if(p[j]=='*'){
                    Dp[i][j] = Dp[i+1][j]||Dp[i][j+1];
                }
                else
                    Dp[i][j] = false;
            }
        }
        return Dp[0][0];
    }
};