class Solution {
public:
    string getHint(string secret, string guess) {
        int len = secret.length();
        string ret;
        int A = 0;
        int B = 0;
        unordered_map<char,int> temp;
        for(int i=0;i<len;++i){
            if(secret[i]==guess[i]){
                ++A;
            }
            else{
                temp[secret[i]]++;
            }
        }
        for(int i=0;i<len;++i){
            if(secret[i]!=guess[i]){
                if(temp[guess[i]]!=0){
                    ++B;
                    temp[guess[i]]--;
                }
            }
        }
        ret = to_string(A)+'A'+to_string(B)+'B';
        return ret;
     }
};