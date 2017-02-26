<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        if (k == 0 || n < 2)
            return 0;

        if (k > n / 2) {
            // like the 122.II version
            int ret = 0;
            for (int i = 1; i < n; ++i)
                if (prices[i] > prices[i - 1])
                    ret += prices[i] - prices[i - 1];
            return ret;
        }

        vector<int> buy(k, INT_MIN);
        vector<int> sell(k, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = k - 1; j >= 0; --j) {
                sell[j] = max(sell[j], buy[j] + prices[i]);
                if (j == 0)
                    buy[j] = max(buy[j], -prices[i]);
                else
                    buy[j] = max(buy[j], sell[j - 1] - prices[i]);
            }
        }
        return sell[k - 1];
    }
};

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        if (prices.empty()) 
            return 0;
        int ans = 0;
        if (k >= prices.size())
        {
            
            for (int i = 1; i < prices.size(); ++i) {
                if (prices[i] - prices[i - 1] > 0) {
                    ans += prices[i] - prices[i - 1];
                }
            }
        } else {

            
            vector<int> local(k+1);
            vector<int> global(k+1);
            
            for (int i = 0; i < prices.size() - 1; ++i) {
                int increase = prices[i + 1] - prices[i];
    
                for (int j = k; j >= 1; --j) {
                    local[j] = max(global[j - 1] + max(increase, 0), local[j] + increase);
                    global[j] = max(global[j], local[j]);
                }
            }
            ans = global[k];
        }
        return ans;
    }
   
};


int main() {

    return 0;
}

=======
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        if (k == 0 || n < 2)
            return 0;

        if (k > n / 2) {
            // like the 122.II version
            int ret = 0;
            for (int i = 1; i < n; ++i)
                if (prices[i] > prices[i - 1])
                    ret += prices[i] - prices[i - 1];
            return ret;
        }

        vector<int> buy(k, INT_MIN);
        vector<int> sell(k, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = k - 1; j >= 0; --j) {
                sell[j] = max(sell[j], buy[j] + prices[i]);
                if (j == 0)
                    buy[j] = max(buy[j], -prices[i]);
                else
                    buy[j] = max(buy[j], sell[j - 1] - prices[i]);
            }
        }
        return sell[k - 1];
    }
};

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        if (prices.empty()) 
            return 0;
        int ans = 0;
        if (k >= prices.size())
        {
            
            for (int i = 1; i < prices.size(); ++i) {
                if (prices[i] - prices[i - 1] > 0) {
                    ans += prices[i] - prices[i - 1];
                }
            }
        } else {

            
            vector<int> local(k+1);
            vector<int> global(k+1);
            
            for (int i = 0; i < prices.size() - 1; ++i) {
                int increase = prices[i + 1] - prices[i];
    
                for (int j = k; j >= 1; --j) {
                    local[j] = max(global[j - 1] + max(increase, 0), local[j] + increase);
                    global[j] = max(global[j], local[j]);
                }
            }
            ans = global[k];
        }
        return ans;
    }
   
};


int main() {

    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
