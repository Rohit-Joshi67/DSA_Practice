class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = INT_MIN;
        int profit = 0;
        int l=0;
        int r= 1;
        if(prices.size()<2){
        return 0;
        }
        else {
        while(r<prices.size()) {
            if(prices[l]>prices[r])
            {
                l=r;
            }
            profit= prices[r]-prices[l];
            r++;
            maxProfit= max(maxProfit,profit);
        }
        }
        return maxProfit;
        
    }
};
