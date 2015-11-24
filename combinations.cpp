class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<int> temp;
        vector<vector<int> > ret;
        temp.resize(k);
        solve(0,k,n,temp,ret,1);
        return ret;
    }
    void solve(int dep,int k,int n,vector<int>temp,vector<vector<int> >&ret,int start){
        if(dep==k){
            ret.push_back(temp);
            return;
        }
        else{
            for(int i=start; i<n+1; ++i){
                temp[dep]=i;
                solve(dep+1,k,n,temp,ret,i+1);
            }
        }
    }
};