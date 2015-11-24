class Solution {
public:
    string convertToTitle(int n) {
        string ret = "";
        while(n)
        {
            ret = (char)('A'+(n-1)%26)+ret;
            n = (n-1)/26;
        }
        return ret;
      
    }
};