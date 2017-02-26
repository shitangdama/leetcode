<<<<<<< HEAD

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // the set only record k (or less than k) numbers before nums[i]
        set<int> st;
        for (int i = 0; i < nums.size(); ++i) {
            if (st.find(nums[i]) != st.end()) {
                return true;
            }
            if (st.size() < k) {
                st.insert(nums[i]);
            } else {
                // insert first, or wrong when k=0
                st.insert(nums[i]);
                st.erase(nums[i - k]);
            }
        }
        return false;
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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // the set only record k (or less than k) numbers before nums[i]
        set<int> st;
        for (int i = 0; i < nums.size(); ++i) {
            if (st.find(nums[i]) != st.end()) {
                return true;
            }
            if (st.size() < k) {
                st.insert(nums[i]);
            } else {
                // insert first, or wrong when k=0
                st.insert(nums[i]);
                st.erase(nums[i - k]);
            }
        }
        return false;
    }
};

int main() {

    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
