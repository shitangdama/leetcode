#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0)
            return 0;
        vector<int> left(n);
        int buy_price = prices[0], profit = 0;

        // pre deal the left
        for (int i = 1; i < n; ++i) {
            buy_price = min(buy_price, prices[i]);
            profit = max(profit, prices[i] - buy_price);
            left[i] = profit;
        }

        int ret = left[n - 1];
        buy_price = prices[n - 1];
        profit = 0;
        // deal the right and get result
        for (int i = n - 1; i >= 1; --i) {
            buy_price = max(buy_price, prices[i]);
            profit = max(profit, buy_price - prices[i]);
            ret = max(ret, profit + left[i - 1]);
        }
        return ret;
    }
};

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0) {
            return 0;
        }
        
        vector<int> profit(prices.size());
        int buy = 0;
        buy = prices[0];
        profit[0] = 0;
        for (int i = 1; i < prices.size(); i++) {
            profit[i] = max(profit[i - 1], prices[i] - buy);
            buy = min(buy, prices[i]);
        }
        
        int sell = prices[prices.size() - 1];
        int best = 0;
        for (int i = prices.size() - 2; i >= 0; i--) {
            best = max(best, sell - prices[i] + profit[i]);
            sell = max(sell, prices[i]);
        }
        
        return best;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto & i : arr)
        cin >> i;
    Solution s;
    cout << s.maxProfit(arr) << endl;
    return 0;
}

