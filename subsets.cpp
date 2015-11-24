class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<int> temp;
        vector<vector<int> >ret;
        sort(S.begin(),S.end());
        dfs(ret,temp,S,0);
        return ret;
        
    }
    void dfs(vector<vector<int> >&ret,vector<int> temp,vector<int> &S,int i){
        if(i==S.size()){
            ret.push_back(temp);
            return;
        }
        else{
            dfs(ret,temp,S,i+1); //not place this element
            temp.push_back(S[i]);//place this element
            dfs(ret,temp,S,i+1);
        }
        
    }
};