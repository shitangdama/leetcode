#include <bits/stdc++.h>

using namespace std;

// LeetCode, Restore IP Addresses
// ʱ�临�Ӷ�O(n^4)���ռ临�Ӷ�O(n)
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string ip; // ����м���
        dfs(s, 0, 0, ip, result);
        return result;
    }

    /**
     * @brief �����ַ���
     * @param[in] s �ַ�������������
     * @param[in] startIndex ��s�����￪ʼ
     * @param[in] step ��ǰ�����ţ���0��ʼ��ţ�ȡֵΪ0,1,2,3,4��ʾ������
     * @param[out] intermediate ��ǰ�����������м���
     * @param[out] result ������п��ܵ�IP��ַ
     * @return ��
     */
    void dfs(string s, size_t start, size_t step, string ip,
            vector<string> &result) {
        if (start == s.size() && step == 4) {  // �ҵ�һ���Ϸ���
            ip.resize(ip.size() - 1);
            result.push_back(ip);
            return;
        }

        if (s.size() - start > (4 - step) * 3)
            return;  // ��֦
        if (s.size() - start < (4 - step))
            return;  // ��֦

        int num = 0;
        for (size_t i = start; i < start + 3; i++) {
            num = num * 10 + (s[i] - '0');

            if (num <= 255) {  // ��ǰ���Ϸ�����������µݹ�
                ip += s[i];
                dfs(s, i + 1, step + 1, ip + '.', result);
            }
            if (num == 0) break;  // ������ǰ׺0����������0
        }
    }
};
int main() {
    Solution s;
    string ss;
    while (cin >> ss) {
        vector<string> res = s.restoreIpAddresses(ss);
        for (auto &i : res)
            cout << i << endl;
    }
    return 0;
}

