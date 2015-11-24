class Solution {
public:
    string addBinary(string a, string b) {
        int cin = 0;
        if(a.size()<b.size()){
            string temp;
            temp = a;
            a = b;
            b = temp;
        }
        string ret;
        int m = a.size();
        int n = b.size();
        for(int i = m-1;i>=0;--i){
            if(i>=m-n){
                ret+=((a[i]-'0')^(b[i-m+n]-'0')^cin+'0');
                cin = (a[i]-'0'+b[i-m+n]-'0'+cin)>1?1:0;
            }
            if(i<m-n){
                ret+=((a[i]-'0')^cin+'0');
                cin = (a[i]-'0'+cin)>1?1:0;
            }
        }
            if(cin>0)
               ret += '1';
            reverse(ret);
            return ret;
            
    }
    void reverse(string &a){
        int i=0;
        int j=a.size()-1;
        while(i<j){
            char temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            ++i;
            --j;
        }
    }
};