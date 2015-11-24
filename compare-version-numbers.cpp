class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m1=0;
        float n1=0;
        int m2=0;
        float n2=0;
        ToInt(version1,m1,n1);
        ToInt(version2,m2,n2);
        if(m1>m2)
            return 1;
        if(m1<m2)
            return -1;
        if(m1==m2){
            if(n1>n2)   return 1;
            if(n1<n2)   return -1;
            if(n1==n2)  return 0;
        }   
    }
    void ToInt(string s,int &m,float &n){
        int sz=s.size();
        int flag = 0;
        int i = 0;
        for(;i<sz;++i){
            if(s[i]=='.') break;
            else{
                m = m*10+s[i]-'0';
            }
        }
        for(i=i+1;i<sz;++i){
            if(s[i]=='.') {
                if(s[i+1]!='0')
                    flag ++;
                if(s[i+1]=='0'&&i+2>sz-1)
                    break;
                continue;
            }
            n = n*10+s[i]-'0';
        }
        while(flag>0){
            n=n/10;
            --flag;
        }
    }
};