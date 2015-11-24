class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string ret = "1";
        for(int i = 1; i<n; ++i){
            ret = nextString(ret);
        }
        return ret;
    }
    string nextString(string s){
        char temp = s[0];
        s = s+'a';
        string ret;
        int index = 1;
        for(int i=1; i<s.length(); ++i){
            if(s[i]==temp){
                index++;
            }
            else{
                char count = '0'+index;
                ret = ret+count;
                ret = ret+temp;
                index = 1;
                temp = s[i];
            }
        }
        return ret;
    }
};