<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.empty())
            return 0;
        vector<int> dp(triangle.size() + 1, INT_MAX);
        dp[1] = triangle[0][0]; // init
        for (int i = 1; i < triangle.size(); ++i) {
            for (int j = i + 1; j > 0; --j)
                dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j - 1];
        }
        return *min_element(dp.begin(), dp.end());
    }
};
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.size() == 0) return 0;

        int height = triangle.size();
        for(int i = height - 2; i >= 0; i --) {
            for(int j = 0; j <= i; j ++) {
                int t1 = triangle[i + 1][j];
                int t2 = triangle[i + 1][j + 1];
                triangle[i][j] += t1 < t2 ? t1 : t2;
            }
        }
        return triangle[0][0];
    }

};

int main() {
    int n, t;
    cin >> n;
    vector<vector<int> > tri(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> t;
            tri[i].push_back(t);
        }
    }
    Solution s;
    cout << s.minimumTotal(tri) << endl;
    return 0;
}

=======
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.empty())
            return 0;
        vector<int> dp(triangle.size() + 1, INT_MAX);
        dp[1] = triangle[0][0]; // init
        for (int i = 1; i < triangle.size(); ++i) {
            for (int j = i + 1; j > 0; --j)
                dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j - 1];
        }
        return *min_element(dp.begin(), dp.end());
    }
};
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.size() == 0) return 0;

        int height = triangle.size();
        for(int i = height - 2; i >= 0; i --) {
            for(int j = 0; j <= i; j ++) {
                int t1 = triangle[i + 1][j];
                int t2 = triangle[i + 1][j + 1];
                triangle[i][j] += t1 < t2 ? t1 : t2;
            }
        }
        return triangle[0][0];
    }

};

int main() {
    int n, t;
    cin >> n;
    vector<vector<int> > tri(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> t;
            tri[i].push_back(t);
        }
    }
    Solution s;
    cout << s.minimumTotal(tri) << endl;
    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
