class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<vector<int> > Dp(s.size()+1,vector<int>());
        vector<string> ret;
        Dp[0].push_back(0);
        if(s.size()<1)
            return ret;
        for(int i=1;i<s.size()+1;++i)
            for(int j=0;j<i;++j){
                if(Dp[j].size()!=0&&wordDict.find(s.substr(j,i-j))!=wordDict.end()){
                    Dp[i].push_back(j);
                }
            }
        GetResult(ret,Dp,s,s.size());
        return ret;
    }
    void GetResult(vector<string> &ret,vector<vector<int> >Dp,string s,int index){
        for(auto i=0;i<Dp[index].size();++i){
            if(Dp[index][i]==0){
                ret.push_back(s);
                continue;
            }
            s.insert(s.begin()+Dp[index][i],' ');
            GetResult(ret,Dp,s,Dp[index][i]);
            s.erase(Dp[index][i],1);
        }
    }
};