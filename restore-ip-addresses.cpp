class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        string ip;
        dfs(s,0,0,ip,ret);
        return ret;
    }
    void dfs(string s,size_t start,int step,string ip,vector<string> &ret){
        if(start==s.size()&&step==4){
            ip.resize(ip.size()-1);
            ret.push_back(ip);
            return;
        }
        if(s.size()-start>3*(4-step))
            return;
        if(s.size()-start<4-step)
            return;
        int num = 0;
        for(size_t i=start; i<start+3; ++i){
            ip =ip+s[i];
            num = 10 * num + s[i]-'0';
            if(num <= 255)
                dfs(s,i+1,step+1,ip+'.',ret);
            if(num == 0) //no single 0
                break;
        }
    }
};