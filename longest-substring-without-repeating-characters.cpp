class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0;
        int length = s.size();
        if(length == 0)
            return 0;
        string rec;
        for(int i=0;i<length;++i){
            if(rec.find(s[i])>=0){
                rec.erase(rec.begin(),rec.begin()+rec.find(s[i])+1);
            }
            rec += s[i];
            ret = rec.size()>ret?rec.size():ret;
        }
        return ret;
    }
};