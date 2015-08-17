#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int buy = 0;
        int profit = 0;
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[buy] > prices[i])
                buy = i;
            profit = max(profit, prices[i] - prices[buy]);
        }
    }
};

int main() {

    return 0;
}

