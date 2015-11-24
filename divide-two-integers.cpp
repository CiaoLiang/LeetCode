class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0){
            return 0x7FFFFFFF;
        }
        unsigned long res=0;
        int flag=1;
        if((dividend<0 && divisor>0)||(dividend>0 && divisor<0))
            flag=-1;
 
        long long divid=abs((long long)dividend);//考虑对最大最小整数取模的情况
        long long divi=abs((long long)divisor);
        long long temp=0;
 
        while(divi<=divid)
        {
            int cnt=1;
            temp=divi;
 
            while((temp<<=1)<=divid)
            {
                cnt<<=1;
            }
            res+=cnt;
            divid-=(temp>>1);
        }
        if(flag==1)
        return res>2147483647?2147483647:(int)res;
        if(flag==-1)
        return -res;
    }
};