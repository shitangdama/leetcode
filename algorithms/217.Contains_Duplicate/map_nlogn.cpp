#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> mp;
        for (auto i : nums) {
            if (mp.find(i) != mp.end()) {
                return true;
            }
            mp[i] = 1;
        }
        return false;
    }
};

int main() {

    return 0;
}

