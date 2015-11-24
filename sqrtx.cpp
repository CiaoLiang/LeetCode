class Solution {
public:
    int sqrt(int x) {
        if(x==0)
        return 0;
        double pre;
        double ret = 1;
        while(abs(pre-ret)>1E-5)
        {
            pre=ret;
            ret=(pre+x/pre)/2.0;
        }//cannot wirte while
        return int(ret);
    }
};