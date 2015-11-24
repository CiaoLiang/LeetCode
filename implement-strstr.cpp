class Solution {
public:
    int strStr(string haystack, string needle) {
        int hLen = haystack.length();
        int nLen = needle.length();
        if(nLen==0)
            return 0;
        if(hLen== 0||hLen-nLen<0)
            return -1;
        for(int i=0;i<hLen-nLen+1;++i){
            if(haystack.substr(i,nLen) == needle)
                return i;
        }
        return -1;
    }
};