class Solution {
public:
    string longestPalindrome(string s) {
        string sc;
        sc += '#';
        
        for(int i=0; i<s.length(); ++i){
            sc += s[i];
            sc += '#';
        }
        
        vector<int> p(sc.length());
        p[0]=1;
        int id = 0; //mid
        int mx = 0; //depth
        int max = 0;
        int index = 0;
        
        for(int i=0;i<sc.length();++i){
            if(mx>i){
                p[i]=min(p[2*id-i],mx-i);
            }
            else
                p[i]=1;
            
            while(sc[i+p[i]]==sc[i-p[i]]&& i-p[i] >=0 &&i+p[i]<sc.length())
                p[i]++;
            
            if(p[i]+i>mx){
                id = i;
                mx = p[i]+i;
            }
            if(p[i]>max){
                max = p[i];
                index = i;
            }
        }
        string cret = sc.substr(index-p[index]+1,2*p[index]-1);
        string ret;
        for(int i=0;i<cret.length();++i){
            if(cret[i]=='#')
                continue;
            else
                ret += cret[i];
        }
        return ret;
    }
};