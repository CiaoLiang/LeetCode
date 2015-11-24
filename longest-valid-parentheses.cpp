class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> Dp(s.size(),0);
        int maxlen;
        if(s.size()<2)
            return 0;
        for(int i=s.size()-2; i>=0; --i){
            int match = Dp[i+1]+i+1; //the last match ')'
            if(s[i]=='(' && match<s.size()&&s[match]==')'){ //match<s.size() not the last
                Dp[i] = Dp[i+1]+2;
                if(match+1<s.size()){ //((()))(....)
                    Dp[i] += Dp[match+1];
                }
            }
            maxlen = max(Dp[i],maxlen);
        }
        return maxlen;
    }
};