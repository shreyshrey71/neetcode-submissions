class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPriceEncountered = prices[0], maxProfitEarned = 0;
        for(int i=1; i<prices.size(); i++){
            maxProfitEarned=max(maxProfitEarned,prices[i]-minPriceEncountered);
            minPriceEncountered=min(minPriceEncountered, prices[i]);
        }
        return maxProfitEarned;
    }
};
