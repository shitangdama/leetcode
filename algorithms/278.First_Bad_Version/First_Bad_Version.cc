<<<<<<< HEAD
bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    int l = 1, h = n;
    while (l < h) {
      int m = l+(h-l)/2;
      if (isBadVersion(m))
        h = m;
      else
        l = m+1;
    }
    return l;
  }
=======
bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    int l = 1, h = n;
    while (l < h) {
      int m = l+(h-l)/2;
      if (isBadVersion(m))
        h = m;
      else
        l = m+1;
    }
    return l;
  }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
};