class Solution {
public:
    string convert(string s, int numRows) {
        int gap = numRows*2-2;
        int length = s.size();
        string ret;
        int index = 0;
        if(numRows==1)
            return s;
        if(length<=numRows)
            return s;
        for(int i=0; i<numRows; ++i){
            index = i;
            if(i==0||i==numRows-1){
                while(index<length){
                    ret += s[index];
                    index += gap;
                }
            }
            else{
                 while(true){
                    if((index - 2*i)>=length)
                        break;
                    if((index-2*i)>0&&(index-2*i)<length)
                        ret += s[index-2*i];
                    if(index<s.size())
                        ret += s[index];
                    index += gap;
                    //if((index - 2*i)>=s.size())
                        //break;
                }
            }
        }
        return ret;
    }
};