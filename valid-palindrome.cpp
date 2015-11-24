class Solution {
public:
    bool isPalindrome(string s) {
        int length = s.size();
        if(length<=1)
            return true;
        int begin = 0;
        int end = length-1;
        while(begin<end){
            while(begin<end&&!isChar(s[begin])){
                begin++;
            }
            while(begin<end&&!isChar(s[end])){
                end--;
            }
            if(tolower(s[begin++])!=tolower(s[end--]))
                return false;
        }
        return true;
    }
    bool isChar(char c){
        if('a'<=c&&c<='z'||'0'<=c&&c<='9'||'A'<=c&&c<='Z')
            return true;
        else 
            return false;
    }
};