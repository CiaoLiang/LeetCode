class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string Prefix;
        int NotPrefix = 1;
        int OutOfRange = 1;
        
        if(strs.size()==0||strs[0].size()==0)
            return Prefix;
            
        for(int i=0;OutOfRange;++i){
            Prefix.push_back(strs[0][i]);
            for(int j=0;j<strs.size();++j){
                if(strs[j][i]!=Prefix[i]){
                    NotPrefix=0;
                    break;
                }
                if(i==strs[j].size()-1){
                    OutOfRange = 0;
                }
            }
            if(NotPrefix==0){
                Prefix.pop_back();
                return Prefix;
            }
        }
        return Prefix;
    }
};