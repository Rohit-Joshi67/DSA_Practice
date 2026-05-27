class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int st = 0;
        int pt = 1;

        int maxP = 0;

        while(pt < prices.size())
        {
            if(prices[pt] < prices[st])
            {
                st = pt;
            }
            else
            {
                int profit = prices[pt] - prices[st];
                maxP = max(maxP, profit);
            }

            pt++;
        }

        return maxP;
    }
};