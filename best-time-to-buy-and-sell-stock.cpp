class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()==0)
        return 0;
        int min = prices[0];
        int profit = 0;
        for(int i=0;i<prices.size();i++){
            profit = (profit>(prices[i]-min))?profit:(prices[i]-min);
            min = (min<prices[i])?min:prices[i];
        }
        return profit;
    }
};