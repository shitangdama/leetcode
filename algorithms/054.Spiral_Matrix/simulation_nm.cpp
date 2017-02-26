<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(matrix.size() == 0) return vector<int>();
        int x1 = 0;
        int y1 = 0;
        int x2 = matrix.size()-1;
        int y2 = matrix[0].size()-1;
        vector<int> ans;
        while(x1 <= x2 && y1 <= y2)
        {
            //up row
            for(int i = y1; i <= y2; ++i) ans.push_back(matrix[x1][i]);
            //right column
            for(int i = x1+1; i <= x2; ++i) ans.push_back(matrix[i][y2]);
            //bottom row
            if(x2 != x1)
            for(int i = y2-1; i >= y1; --i) ans.push_back(matrix[x2][i]);
            //left column
            if(y1 != y2)
            for(int i = x2-1; i > x1; --i) ans.push_back(matrix[i][y1]);
            
            x1++, y1++, x2--, y2--;
        }

        return ans;
    }
};
int main() {
    int n;
    Solution s;
    while (cin >> n) {
        vector<vector<int> > mat(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mat[i].push_back(n * i + j + 1);
        vector<int> ans = s.spiralOrder(mat);
        for (auto &i : ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}

=======
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(matrix.size() == 0) return vector<int>();
        int x1 = 0;
        int y1 = 0;
        int x2 = matrix.size()-1;
        int y2 = matrix[0].size()-1;
        vector<int> ans;
        while(x1 <= x2 && y1 <= y2)
        {
            //up row
            for(int i = y1; i <= y2; ++i) ans.push_back(matrix[x1][i]);
            //right column
            for(int i = x1+1; i <= x2; ++i) ans.push_back(matrix[i][y2]);
            //bottom row
            if(x2 != x1)
            for(int i = y2-1; i >= y1; --i) ans.push_back(matrix[x2][i]);
            //left column
            if(y1 != y2)
            for(int i = x2-1; i > x1; --i) ans.push_back(matrix[i][y1]);
            
            x1++, y1++, x2--, y2--;
        }

        return ans;
    }
};
int main() {
    int n;
    Solution s;
    while (cin >> n) {
        vector<vector<int> > mat(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mat[i].push_back(n * i + j + 1);
        vector<int> ans = s.spiralOrder(mat);
        for (auto &i : ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
