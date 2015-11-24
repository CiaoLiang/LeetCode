class Solution {
public:
    int rob(vector<int> &num) {
        if(num.size()==0)
            return 0;
        int step1=0;
        int step2=0;
        int step3=num[0];
        int step4=0;
        for(int i=1;i<num.size();++i){
            step4=max(num[i]+step2,num[i-1]+step1);
            step1=step2;
            step2=step3;
            step3=step4;
        }
        return step3;
    }
};