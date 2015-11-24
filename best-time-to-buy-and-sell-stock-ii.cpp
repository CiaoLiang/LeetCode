class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()==0)
        return 0;
        int DayProfit = 0;
        int Profit = 0;
        int min = prices[0];
        for(int i=0;i<prices.size();++i){
            if(prices[i]<min){
                min = prices[i];
            }
            if(prices[i]-min>DayProfit){
                DayProfit=prices[i]-min;
            }
            else if(prices[i]-min<DayProfit){
                Profit+=DayProfit;
                min = prices[i];
                DayProfit = 0;
            }
            if(i==prices.size()-1){
                if(prices[i]-min>0){
                    Profit+=prices[i]-min;
                }
            }
        }
        return Profit;
        
    }
};