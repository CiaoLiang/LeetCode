class Solution {
public:
    int atoi(string str) {
        if(str.size()==0)
        return 0;
        long int num = 0;
        int flag = 1;
        auto i = str.begin();
        
       while(*i==' ') i++;
       
       if(*i=='-')  
       {
           flag = -1;
           i++;
       }
       else if(*i=='+')
       {
           flag = 1;
           i++;
       } //'+' or '-'
       
       for(;i!=str.end();++i)
        {
            if(*i>='0'&&*i<='9')
            {
            num=num*10+flag*(*i-'0');
            if(num>=(int)0x7FFFFFFF)
            return 0x7FFFFFFF;
            if(num<=(int)0x80000000)
            return 0x80000000;
            }
            else
            {
                break;
            }
        }
        return num;
    }
};
