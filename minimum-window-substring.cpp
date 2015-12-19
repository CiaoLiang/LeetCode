class Solution {
public:
    string minWindow(string s, string t) {
        int min = INT_MAX;
        int subs = 0;
        vector<int> appearedNum(300,0);
        vector<int> expectNum(300,0);
        for(int i=0; i<t.length(); ++i){
            expectNum[t[i]]++;
        }
        int start=0,end = 0;//初始化
        int count = 0;
        for(end=0; end<s.length(); ++end){
            if(expectNum[s[end]]>0){
                appearedNum[s[end]]++;
                if(appearedNum[s[end]]<=expectNum[s[end]])
                    count++;
            }//统计出现数字
            if(count == t.length()){//出现可收缩解的情况就收缩头指针
                while(appearedNum[s[start]]>expectNum[s[start]]||expectNum[s[start]]==0){
                    appearedNum[s[start]]--;
                    start++;
                }
                if(min>end-start+1){
                    min = end-start+1;
                    subs = start;
                }
            }
        }
        
        if(count<t.length()) return "";
        else    return s.substr(subs,min);
    }
};