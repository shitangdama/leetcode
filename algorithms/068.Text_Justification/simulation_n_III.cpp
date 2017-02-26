#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ans;
        int begin = 0;
        while (begin < words.size()) {
            int last = begin;
            int linesize = words[begin++].size();
            while (begin < words.size() && linesize + 1 + words[begin].size() <= L) {
                linesize += 1 + words[begin].size();
                begin++;
            }

            int spaces = 1, extra = 0;
            if (begin < words.size() && begin != last + 1) {
                spaces = (L - linesize) / (begin - last - 1) + 1;
                extra = (L - linesize) % (begin - last - 1);
            }

            ans.push_back(words[last++]);
            while (extra--) {
                ans.back().append(spaces+1, ' ');
                ans.back().append(words[last++]);
            }
            while (last < begin) {
                ans.back().append(spaces, ' ');
                ans.back().append(words[last++]);
            }
            ans.back().append(L-ans.back().size(), ' ');
        }

        return ans;
    }
};

int main() {
    int n, l;
    cin >> n >> l;
    vector<string> w(n);
    for (auto &i : w)
        cin >> i;
    Solution s;
    vector<string> ans = s.fullJustify(w, l);
    for (auto &i : ans)
        cout << i << endl;

    return 0;
}

