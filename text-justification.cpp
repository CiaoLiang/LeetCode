class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        int idx = 0;
        while(idx<words.size()){
            int total = 0;
            int end = idx;
            while (end < words.size() && total+end-idx+words[end].length() <= maxWidth) {
                total += words[end].length();
                end ++;
            } 
            string s = words[idx];
            if (end == words.size() || end-idx==1) {      
                for (int i = idx+1; i < end; i ++)
                s += " " + words[i];
                s += string(maxWidth-(total+end-idx-1), ' ');
            }
            else {
                int base = (maxWidth-total)/(end-idx-1);
                int left = (maxWidth-total)%(end-idx-1);
                int count = 0;
                for(int i=idx+1; i<end; ++i){
                    if(count<left) {
                        s += string(base+1,' ');
                        s += words[i];
                        ++count;
                    }
                    else {
                        s+= string(base,' ');
                        s+= words[i];
                    }
                }
            }
            ret.push_back(s);
            idx = end;
        }
        return ret;
    }
};