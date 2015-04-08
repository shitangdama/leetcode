#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int ret = 0;
        for (int i = 0; i < n; i++)
            if (A[i] != elem)
                A[ret++] = A[i];
        return ret;
    }
};

int main() {

    return 0;
}

