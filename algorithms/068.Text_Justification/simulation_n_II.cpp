<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
    vector<string> res;
    for(int i = 0, k, l; i < words.size(); i += k) {
        for(k = l = 0; i + k < words.size() and l + words[i+k].size() <= L - k; k++) {
            l += words[i+k].size();
        }
        string tmp = words[i];
        for(int j = 0; j < k - 1; j++) {
            if(i + k >= words.size()) tmp += " ";
            else tmp += string((L - l) / (k - 1) + (j < (L - l) % (k - 1)), ' ');
            tmp += words[i+j+1];
        }
        tmp += string(L - tmp.size(), ' ');
        res.push_back(tmp);
    }
    return res;
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

=======
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
    vector<string> res;
    for(int i = 0, k, l; i < words.size(); i += k) {
        for(k = l = 0; i + k < words.size() and l + words[i+k].size() <= L - k; k++) {
            l += words[i+k].size();
        }
        string tmp = words[i];
        for(int j = 0; j < k - 1; j++) {
            if(i + k >= words.size()) tmp += " ";
            else tmp += string((L - l) / (k - 1) + (j < (L - l) % (k - 1)), ' ');
            tmp += words[i+j+1];
        }
        tmp += string(L - tmp.size(), ' ');
        res.push_back(tmp);
    }
    return res;
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

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
