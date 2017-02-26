#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        if (S.empty() || T.empty())
            return "";
        int slen = S.length(), tlen = T.length();
        int res_pos = 0;                // position of result
        int min_len = INT_MAX;
        int count = 0;                  // match count in window
        int sta[255] = {0};             // array map: state and window
        int wnd[255] = {0};
        int slow = 0, fast = 0;         // pointer

        // deal T
        for (int i = 0; i < tlen; ++i)
            ++sta[T[i]];

        // count
        for (int fast = 0; fast < slen; ++fast) {
            int idx = S[fast];
            ++wnd[idx];
            if (wnd[idx] <= sta[idx])
                ++count;
            
            // match enough
            if (count >= tlen) {
                while (wnd[S[slow]] > sta[S[slow]])
                    --wnd[S[slow++]];      // equal to: wnd[S[slow]]--; slow++;
                if (fast - slow + 1 < min_len) {
                    min_len = fast - slow + 1;
                    res_pos = slow;
                }
                // make it not enough again
                --wnd[S[slow++]];
                --count;
            }
        }
        return S.substr(res_pos, min_len == INT_MAX ? 0 : min_len);
    }
};

// LeetCode, Minimum Window Substring
// 时间复杂度O(n)，空间复杂度O(1)
class Solution 2{
public:
    string minWindow(string S, string T) {
        if (S.empty()) return "";
        if (S.size() < T.size()) return "";

        const int ASCII_MAX = 256;
        int appeared_count[ASCII_MAX];
        int expected_count[ASCII_MAX];
        fill(appeared_count, appeared_count + ASCII_MAX, 0);
        fill(expected_count, expected_count + ASCII_MAX, 0);

        for (size_t i = 0; i < T.size(); i++) expected_count[T[i]]++;

        int minWidth = INT_MAX, min_start = 0;  // 窗口大小，起点
        int wnd_start = 0;
        int appeared = 0;  // 完整包含了一个T
        //尾指针不断往后扫
        for (size_t wnd_end = 0; wnd_end < S.size(); wnd_end++) {
            if (expected_count[S[wnd_end]] > 0)  {  // this char is a part of T
                appeared_count[S[wnd_end]]++;
                if (appeared_count[S[wnd_end]] <= expected_count[S[wnd_end]])
                    appeared++;
            }
            if (appeared == T.size()) {  // 完整包含了一个T
                // 收缩头指针
                while (appeared_count[S[wnd_start]] > expected_count[S[wnd_start]]
                        || expected_count[S[wnd_start]] == 0) {
                    appeared_count[S[wnd_start]]--;
                    wnd_start++;
                }
                if (minWidth > (wnd_end - wnd_start + 1)) {
                    minWidth = wnd_end - wnd_start + 1;
                    min_start = wnd_start;
                }
            }
        }

        if (minWidth == INT_MAX) return "";
        else return S.substr(min_start, minWidth);
    }
};


int main() {
    string S, T;
    Solution s;
    while (cin >> S >> T)
        cout << s.minWindow(S, T) << endl;
    return 0;
}

