class Solution {
public:
    int numDecodings(string s) {
        vector<int> Dp(s.size()+1,0);
        Dp[0] = 1;
        Dp[1] = 1;
        if(s.size()==0||s[0]=='0')
            return 0;
        for(int i = 2;i<s.size()+1;++i){
            if(s[i-1]=='0'){
                Dp[i]=Dp[i-2];
                if(s[i-2]!='2'&&s[i-2]!='1'){
                    return 0;
                }
            }
            else{
                if(s.substr(i-2,2)=="20"||s.substr(i-2,2)=="10")
                    Dp[i]=Dp[i-2];
                else if((s.substr(i-2,2)[0]>'0'&&s.substr(i-2,2)[0]<'2')||(s.substr(i-2,2)[0]=='2'&&(s.substr(i-2,2)[1]<='6')))
                    Dp[i]=Dp[i-1]+Dp[i-2];
                else
                    Dp[i]=Dp[i-1];
            }
        }
        return Dp[s.size()];
    }
};