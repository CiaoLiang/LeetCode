class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> F(s.length()+1,false);
        F[0]=true;
        for(int i=1;i<s.length()+1;++i)
            for(int j=0;j<i;++j){
                if(F[j]&&wordDict.find(s.substr(j,i-j))!=wordDict.end()){
                    F[i] = true;
                }
            }
        return F[s.length()];
    }
};