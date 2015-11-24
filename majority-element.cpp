class Solution {
public:
    int majorityElement(vector<int> &num) {
        //moore vote alogrithm .if there are two numbers not equal count--,else count++.If count=0 than change the answer to the next.But Stil Not Very Clear.
        int ret = 0;
        int count = 0;
        for(int i=0;i<num.size();i++){
            if(count==0){
                ret = num[i];
                count++;
            }
            else{
                if(ret==num[i])
                count++;
                else
                count--;
            }
        }
        return ret;
        
    }
};