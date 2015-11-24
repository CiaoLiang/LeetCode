class Solution {
public:
    int reverse(int x) {
        long int ret = 0;
        long int tx = x;
        int flag = 1;
        if(tx<0)
            {
                flag = -1;
                tx = -tx;
            }
        long int temp = 0;
        while(tx)
        {
            ret = ret*10;
            ret = ret + tx%10;
            tx = tx/10;
        }
        
        if(flag==-1) ret=0-ret;
        if((ret>(int)0x7FFFFFFF)||(ret<(int)0x80000000))
            return 0;
        return ret;
    }
};