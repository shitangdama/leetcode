<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
int i = 0;
int j = matrix[0].size() - 1;

while(i < matrix.size() && j >= 0) {
    if(matrix[i][j] == target)
        return true;

    if(matrix[i][j] < target)
        i++;
    else
        j--;
}

return false;
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
int i = 0;
int j = matrix[0].size() - 1;

while(i < matrix.size() && j >= 0) {
    if(matrix[i][j] == target)
        return true;

    if(matrix[i][j] < target)
        i++;
    else
        j--;
}

return false;
}
};

int main() {

    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
