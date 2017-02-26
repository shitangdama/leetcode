<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = n * m - 1, mid = 0;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (matrix[mid/m][mid%m] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return matrix[l/m][l%m] == target;
    }
};

int main() {
    return 0;
}

=======
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = n * m - 1, mid = 0;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (matrix[mid/m][mid%m] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return matrix[l/m][l%m] == target;
    }
};

int main() {
    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
