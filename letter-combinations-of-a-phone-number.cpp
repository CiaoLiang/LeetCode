class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        vector<string> Num = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string temp;
        if(digits.size()==0)
            return ret;
        Dfs(digits,ret,Num,temp,0);
        return ret;
    }
    void Dfs(string digits,vector<string> &ret,vector<string>Num,string temp,int index){
        if(index==digits.size()){
            ret.push_back(temp);
            return;
        }
        int digit = digits[index]-'2';
        for(int i=0;i<Num[digit].size();++i ){
            temp.push_back(Num[digit][i]);
            Dfs(digits,ret,Num,temp,index+1);
            temp.pop_back();
        }
    }
};