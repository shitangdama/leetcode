<<<<<<< HEAD
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> full(2, INT_MIN), empty(2, 0), sell(2, 0);
        for (int i = 0; i < prices.size(); i++) {
            full[i % 2] = max(full[1 - i % 2], empty[1 - i % 2] - prices[i]);  
                // had bought before OR buy today (pay prices[i])
            sell[i % 2] = full[1 - i % 2] + prices[i];  
                // sell today (get prices[i])
            empty[i % 2] = max(empty[1 - i % 2], sell[1 - i % 2]);  
                // had sold before yesterday OR sold yesterday
        }
        return max(empty[1 - prices.size() % 2], sell[1 - prices.size() % 2]);
    }
};

int maxProfit(vector<int> &prices) {
    int buy(INT_MIN), sell(0), prev_sell(0), prev_buy;
    for (int price : prices) {
        prev_buy = buy;
        buy = max(prev_sell - price, buy);
        prev_sell = sell;
        sell = max(prev_buy + price, sell);
    }
    return sell;
=======
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> full(2, INT_MIN), empty(2, 0), sell(2, 0);
        for (int i = 0; i < prices.size(); i++) {
            full[i % 2] = max(full[1 - i % 2], empty[1 - i % 2] - prices[i]);  
                // had bought before OR buy today (pay prices[i])
            sell[i % 2] = full[1 - i % 2] + prices[i];  
                // sell today (get prices[i])
            empty[i % 2] = max(empty[1 - i % 2], sell[1 - i % 2]);  
                // had sold before yesterday OR sold yesterday
        }
        return max(empty[1 - prices.size() % 2], sell[1 - prices.size() % 2]);
    }
};

int maxProfit(vector<int> &prices) {
    int buy(INT_MIN), sell(0), prev_sell(0), prev_buy;
    for (int price : prices) {
        prev_buy = buy;
        buy = max(prev_sell - price, buy);
        prev_sell = sell;
        sell = max(prev_buy + price, sell);
    }
    return sell;
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
}