<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;
        vector<bool> noprime(n, false);

        int sum = 0;
        int bound = sqrt(n);
        for (int i = 2; i < n; ++i) {
            if (!noprime[i]) {
                ++sum;
                if (i > bound)
                    continue;
                for (int j = i * i; j < n; j += i)
                    noprime[j] = true;
            }
        }
        return sum;
    }
};
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        double c = sqrt(n);
        bool *bv = new bool[n];
        for(int i = 3; i <= c; i += 2)
            if (!bv[i]) 
                for(int j = i*i, k = i << 1; j < n; j += k)
                    bv[j] = 1;
        int num = 1;
        for(int i = 3; i < n; i += 2)
            if(!bv[i]) num++;
        return num;
    }
};

class Solution {
 public:
  // O(n) space, O(nloglogn) time
  int countPrimes(int n) {
    if(n == 0) return 0;
    vector<bool> table(n, true);
    for(int i = 2; i * i < n; i ++) {
      if(!table[i]) continue;
      for(int j = i * i; j < n; j += i) table[j] = false;
    }
    int result = 0;
    for(int i = 2; i < n; ++i) {
      if(table[i]) result += 1;
    }
    return result;
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
    int countPrimes(int n) {
        if (n <= 2)
            return 0;
        vector<bool> noprime(n, false);

        int sum = 0;
        int bound = sqrt(n);
        for (int i = 2; i < n; ++i) {
            if (!noprime[i]) {
                ++sum;
                if (i > bound)
                    continue;
                for (int j = i * i; j < n; j += i)
                    noprime[j] = true;
            }
        }
        return sum;
    }
};
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        double c = sqrt(n);
        bool *bv = new bool[n];
        for(int i = 3; i <= c; i += 2)
            if (!bv[i]) 
                for(int j = i*i, k = i << 1; j < n; j += k)
                    bv[j] = 1;
        int num = 1;
        for(int i = 3; i < n; i += 2)
            if(!bv[i]) num++;
        return num;
    }
};

class Solution {
 public:
  // O(n) space, O(nloglogn) time
  int countPrimes(int n) {
    if(n == 0) return 0;
    vector<bool> table(n, true);
    for(int i = 2; i * i < n; i ++) {
      if(!table[i]) continue;
      for(int j = i * i; j < n; j += i) table[j] = false;
    }
    int result = 0;
    for(int i = 2; i < n; ++i) {
      if(table[i]) result += 1;
    }
    return result;
  }
};

int main() {

    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
