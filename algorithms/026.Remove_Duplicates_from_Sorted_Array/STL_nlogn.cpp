#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        return distance(A, unique(A, A + n));
    }
};

int main() {

    return 0;
}

