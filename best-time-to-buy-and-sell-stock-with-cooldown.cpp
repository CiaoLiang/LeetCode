class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pre_buy = INT_MIN;
        int buy = INT_MIN;
        int pre_sell = 0;
        int sell = 0;
        for(int i=0; i<prices.size();++i){
            pre_buy = buy; //pre_buy记录buy[i-1]
            buy = max(pre_sell-prices[i],buy);//buy计算buy[i],更新buy[i-1]到buy[i]
            pre_sell = sell; //pre_sell,sell[i-2]更新到sell[i-1];
            sell = max(pre_buy+prices[i],sell); //sell计算sell[i],更新sell[i-1]到sell[i]
        }
        return sell;
    }
};
