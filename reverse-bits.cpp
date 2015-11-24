class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t p1=0x01;
        uint32_t p2=0x80000000;
        uint32_t result=0;
        while(p1)
        {
            if(n&p1)
              result=result|p2;
            p1=p1<<1;
            p2=p2>>1;
        }
        return result;
    }
};