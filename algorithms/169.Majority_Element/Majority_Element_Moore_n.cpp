<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        int count = 0;
        int major;
        for (auto &i : num) {
            if (count == 0)
                major = i;
            if (i == major)
                count++;
            else
                cout--;
        }
        return major;
    }
};
class Solution {
public:
    int majorityNumber(vector<int> nums) {
        int candidate, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                candidate = nums[i];
                count ++;
            } else {
                if (candidate == nums[i]) {
                    count ++;
                } else {
                    count --;
                }
            }
        }
        return candidate;
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
    int majorityElement(vector<int> &num) {
        int count = 0;
        int major;
        for (auto &i : num) {
            if (count == 0)
                major = i;
            if (i == major)
                count++;
            else
                cout--;
        }
        return major;
    }
};
class Solution {
public:
    int majorityNumber(vector<int> nums) {
        int candidate, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                candidate = nums[i];
                count ++;
            } else {
                if (candidate == nums[i]) {
                    count ++;
                } else {
                    count --;
                }
            }
        }
        return candidate;
    }
};

int main() {

    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
