#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int start, cur_station, k, n = gas.size();

        for (start = 0; start < n; start += k + 1) {
            int cur_gas = 0;
            for (k = 0; k < n; ++k) { // cross k stations
                cur_station = (start + k) % n;
                cur_gas += gas[cur_station] - cost[cur_station];
                if (cur_gas < 0)
                    break;
            }
            if (cur_gas >= 0)
                return start;
        }

        return -1;
    }
};
// LeetCode, Gas Station
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int total = 0;
        int j = -1;
        for (int i = 0, sum = 0; i < gas.size(); ++i) {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (sum < 0) {
                j = i;
                sum = 0;
            }
        }
        return total >= 0 ? j + 1 : -1;
    }
};
int main() {

    return 0;
}

