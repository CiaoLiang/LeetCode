/*Inspired by Manual calculation process*/
class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        if(num1=="0"||num2=="0")
            return "0";
        vector<int> res(len1+len2,0); 
        
        for(int i=0; i<len1; ++i)
            for(int j=0; j<len2; ++j)
                res[i+j+1] += (num1[i]-'0')*(num2[j]-'0'); //multiply but not carry
                
        string s = "";
        for(int k = len1+len2-1; k>=0; --k){ //vector int change to string
            if(k>0)
                res[k-1] += res[k]/10;
            res[k] = res[k]%10;
            char temp = '0'+res[k];
            s = temp+s;
        }
        return s[0]=='0'?s.substr(1):s;
    }
};