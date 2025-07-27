class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int min_price = prices[0];
        int max_profit = 0;

        for (int i = 1; i < prices.size(); ++i) {
            // Calculate potential profit if we sell today
            int current_profit = prices[i] - min_price;
            
            // Update the maximum profit seen so far
            max_profit = max(max_profit, current_profit);
            
            // Update the minimum buy price for future calculations
            min_price = min(min_price, prices[i]);
        }
        
        return max_profit;
    }
};