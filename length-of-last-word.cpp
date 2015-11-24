class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if(s==NULL)
            return 0;
        int ret=0;
        int flag=0;
        while(*s){
            if(*s!=' ')
                ++ret;
            if(*s==' '&&*(s+1)&&*(s+1)!=' ')
                ret=0;
                ++s;
        }
        return ret;
    }
};