class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maximumProfit = 0;
        int mini = prices[0];
        for(int i=0;i<prices.size();i++){
            int cost = prices[i]-mini;
            maximumProfit = max(maximumProfit,cost);
            mini = min(mini,prices[i]);
        }
        return maximumProfit;
    }
};
