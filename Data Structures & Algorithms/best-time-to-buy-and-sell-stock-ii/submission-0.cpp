class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // this solution if for buy and sell stocks (if we are buying only one time)

        // int profit = 0;
        // int mini = prices[0];
        // for(int i=0;i<prices.size();i++){
        //     int cost = prices[i] - mini;
        //     profit = max(profit,cost);
        //     mini = min(mini,prices[i]);
        // }
        // return profit;

        int profit = 0;
        for(int i=0;i<prices.size()-1;i++){
            if(prices[i] < prices[i+1]){
                profit += prices[i+1]-prices[i];
            }
        }
        return profit;
    }
};