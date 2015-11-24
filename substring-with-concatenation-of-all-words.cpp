class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordlen = words[0].size();
        int strlen = s.size();
        vector<int> result;
        map<string,int> temp;
        map<string,int> Count;
        if(strlen < wordlen*words.size())
            return result;
        for(int i=0;i<words.size();++i){
            ++temp[words[i]];
        }

        for(int i=0; i<=strlen-wordlen*words.size(); ++i){ //important bondary
            Count.clear();
            int j=i;
            for(; j<i+wordlen*words.size(); j=j+wordlen){
                string se = s.substr(j,wordlen);
                if(temp.count(se) != 0){
                    ++Count[se];
                    if(Count[se]>temp[se])
                        break;
                }
                else break;
            }
            
            if(j>=i+wordlen*words.size()){
                result.push_back(i);
            }
            
        }
        return result;
    }
};