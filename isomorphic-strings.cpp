class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> contrast1;
        map<char,char> contrast2;
        for(int i=0; i<s.size(); ++i){
            if(contrast1.find(s[i])!=contrast1.end()){
                if(contrast1[s[i]]!=t[i]||contrast2[t[i]]!=s[i]){
                    return false;
                }
            }
            else {
                contrast1[s[i]] = t[i];
                if(contrast2.find(t[i])!=contrast2.end()){
                    if(contrast1[s[i]]!=t[i]||contrast2[t[i]]!=s[i]){
                    return false;
                 }
                }
                else contrast2[t[i]] = s[i];
            }
        }
        return true;
    }
};