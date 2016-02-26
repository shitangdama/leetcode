#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    static bool cmp(string a, string b) {
        return (a + b) > (b + a);
    }

public:
    string largestNumber(vector<int> &num) {
        vector<string> str;
        for (auto &i : num)
            str.push_back(to_string(i));

        sort(str.begin(), str.end(), cmp);

        string ans;
        if (str[0] == "0")
            return "0";
        for (auto &i : str)
            ans += i;

        return ans;
    }
};
class Solution {
    public:

        //compare function
        static bool comp (string& s1, string& s2) { return s1+s2 > s2+s1; }

        string largestNumber(vector<int> &num) {

            //convert int to string
            vector<string> v;
            for (int i=0; i<num.size(); i++) {
                v.push_back(to_string(num[i]));
            }

            //sort the string
            sort(v.begin(), v.end(), comp);

            //generate the result
            string result;
            for(int i=0; i<v.size(); i++ ){
                result+=v[i];
            }

            //special case: start with zero (e.g. [0, 0])
            if (result[0]=='0') return "0";

            return result;
        }
};

int main() {
    int n, t;
    Solution s;
    cin >> n;
    vector<int> num(n);
    for (auto &i : num)
        cin >> i;
    cout << s.largestNumber(num) << endl;
    return 0;
}

