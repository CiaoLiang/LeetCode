class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        vector<string> ret;
        map<string,int> Map;
        for(int i = 0;i<strs.size();++i){
            string s = strs[i];
            sort(s.begin(),s.end());
            if(Map.find(s)==Map.end()){
                Map[s]=i;
            }
            else{
                if(Map[s]>=0){
                    ret.push_back(strs[Map[s]]);
                    Map[s]=-1;
                }
                ret.push_back(strs[i]);
            }
        }
        return ret;
    }
};