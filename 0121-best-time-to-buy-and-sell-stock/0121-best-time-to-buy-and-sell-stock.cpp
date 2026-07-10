class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int minimum  = prices[0]; // first day stock price
        int max_profit = 0;

        for(int i = 1; i < n; i++){
            int curr_profit = prices[i] - minimum;
            max_profit = max(max_profit, curr_profit);
            minimum = min(prices[i], minimum);
        }
        return max_profit;
    }
};