class Solution {
public:
    int maximumGap(vector<int> &num) {
        if(num.size()<2){
            return 0;
        }
        sort(num.begin(),num.end());
        int maxGap = abs(num[0]-num[1]);
        for(int i=0;i<num.size()-1;i++){
            maxGap = (maxGap>abs(num[i]-num[i+1]))?maxGap:abs(num[i]-num[i+1]);
        }
        return maxGap;
    }
};