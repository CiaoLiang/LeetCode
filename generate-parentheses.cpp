class Solution {
private:
    vector<string> ret;
public:
    vector<string> generateParenthesis(int n) {
        string cur;
        if(n<=0)
        return ret;
        int right= 0;
        int left = 0;
        dfs(right+1,left,cur+'(',n);
        return ret;
    }
    void dfs(int right,int left,string cur,int num){
        if(left==num&&right==num){
            ret.push_back(cur);
            return;
        }
        if(right!=num&&right>left){
            dfs(right+1,left,cur+'(',num);
            dfs(right,left+1,cur+')',num);
        }
        if(right==left){
            dfs(right+1,left,cur+'(',num);
        }
        if(right==num){
           dfs(right,left+1,cur+')',num);
        }
    }
};