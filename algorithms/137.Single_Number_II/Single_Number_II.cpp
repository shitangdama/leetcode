#include <bits/stdc++.h>

using namespace std;

class Solution {
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        const int W = sizeof(int) * 8; // һ��������bit�����������ֳ�
        int count[W];  // count[i]��ʾ����iλ���ֵ�1�Ĵ���
        fill_n(&count[0], W, 0);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < W; j++) {
                count[j] += (nums[i] >> j) & 1;
                count[j] %= 3;
            }
        }
        int result = 0;
        for (int i = 0; i < W; i++) {
            result += (count[i] << i);
        }
        return result;
    }

};
class Solution {
public:
    int singleNumber(vector<int>& nums) {
                int one = 0, two = 0, three = 0;
        for (int i = 0; i < nums.size(); ++i) {
            two |= (one & nums[i]);
            one ^= nums[i];
            three = ~(one & two);
            one &= three;
            two &= three;
        }

        return one;
    }
};
int main() {
    int n, a[100];
    Solution s;
    while (cin >> n) {
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << s.singleNumber(a, n) << endl;
    }
    return 0;
}

