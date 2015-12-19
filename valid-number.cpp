class Solution {
public:
    bool isNumber(string s) {
        int flag = 0; //e flag
        int start = 0;
        int estart = 0;
        int end = s.size()-1;
        int dotcount = 0;
        while(s[start]==' ')
            ++start;
        while(s[end]==' ')
            --end;
        if(s[start]=='+'||s[start]=='-')
            ++start;
        if(start>end)
            return false;
        for(int i=start; i<=end; ++i){
            if(flag == 0){
                if(s[i]=='e'){
                    if(i==start||i==end)
                        return false;
                    flag = 1;
                    estart = i;
                    continue;
                }
                if(!number(s[i])&&(s[i]!='e')&&(s[i]!='.')) //exits other char
                    return false;
                if(s[i]=='.'&&s[i+1]=='e'&&i==start)
                    return false;
                else if(s[i]=='.'&&s[i+1]!='e'){
                    dotcount++;
                    if(dotcount>1)
                        return false;
                    if(i==start&&!number(s[i+1]))
                        return false;
                    if(i==end && !number(s[i-1]))
                        return false;
                    if(i>start&&i<end&&(!number(s[i+1])||!number(s[i-1])))
                        return false;
                }
            }
            if(flag == 1){
                if(estart+1==end&&!number(s[i]))
                    return false;
                if(i==estart+1&&s[i]=='+'||s[i]=='-')
                    continue;
                if(!number(s[i]))
                    return false;
                if(i==end&&!number(s[i]))
                    return false;
            }
         }
        return true;
    }
    bool number(char c){
        return c>='0'&&c<='9';
    }
};