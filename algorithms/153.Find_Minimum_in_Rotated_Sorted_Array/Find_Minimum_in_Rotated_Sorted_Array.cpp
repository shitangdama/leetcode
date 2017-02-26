<<<<<<< HEAD
#include <bits/stdc++.h>

class Solution {
public:
    int findMin(vector<int> &num) {
        int left = 0, right = num.size() - 1;
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (num[left] <= num[mid] && num[mid] <= num[right]) {
                return num[left];
            } else if (num[left] <= num[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return num[0];
    }
};

int main() {
    vector<int> num;
    num.push_back(3);
    num.push_back(1);
    num.push_back(2);
    Solution s;
    cout << s.findMin(num) << endl;
    return 0;
}

=======
#include <bits/stdc++.h>

class Solution {
public:
    int findMin(vector<int> &num) {
        int left = 0, right = num.size() - 1;
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (num[left] <= num[mid] && num[mid] <= num[right]) {
                return num[left];
            } else if (num[left] <= num[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return num[0];
    }
};

int main() {
    vector<int> num;
    num.push_back(3);
    num.push_back(1);
    num.push_back(2);
    Solution s;
    cout << s.findMin(num) << endl;
    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
