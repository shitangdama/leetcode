<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    // 084. Largest Rectangle in Histogram (Hard)
    int largestRectangleArea(vector<int> &height) {
        int ret = 0;
        int len = height.size();
        for (int i = 0; i < len; ++i)
            if (i + 1 >= len || height[i] > height[i + 1]) {
                int mmin = INT_MAX;
                for (int j = i; j >= 0; --j) {
                    mmin = min(mmin, height[j]);
                    ret = max(ret, mmin * (i - j + 1));
                }
            }
        return ret;
    }

public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty()|| matrix[0].empty())
            return 0;

        int ret = 0;
        vector<int> height(matrix[0].size());

        for (auto & mat : matrix) {
            for (int i = 0; i < mat.size(); ++i)
                height[i] = (mat[i] == '0') ? 0 : height[i] + 1;
            ret = max(ret, largestRectangleArea(height));
        }

        return ret;
    }
};

int main() {

    return 0;
}

=======
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    // 084. Largest Rectangle in Histogram (Hard)
    int largestRectangleArea(vector<int> &height) {
        int ret = 0;
        int len = height.size();
        for (int i = 0; i < len; ++i)
            if (i + 1 >= len || height[i] > height[i + 1]) {
                int mmin = INT_MAX;
                for (int j = i; j >= 0; --j) {
                    mmin = min(mmin, height[j]);
                    ret = max(ret, mmin * (i - j + 1));
                }
            }
        return ret;
    }

public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty()|| matrix[0].empty())
            return 0;

        int ret = 0;
        vector<int> height(matrix[0].size());

        for (auto & mat : matrix) {
            for (int i = 0; i < mat.size(); ++i)
                height[i] = (mat[i] == '0') ? 0 : height[i] + 1;
            ret = max(ret, largestRectangleArea(height));
        }

        return ret;
    }
};

int main() {

    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
