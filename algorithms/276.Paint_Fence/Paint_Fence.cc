<<<<<<< HEAD
// Paint Fence
class Solution {
public:
  int numWays(int n, int k) {
    int a = 0, b = k, c = k*k;
    while (n--) {
      a = b;
      b = c;
      c = (a+b)*(k-1);
    }
    return a;
  }
=======
// Paint Fence
class Solution {
public:
  int numWays(int n, int k) {
    int a = 0, b = k, c = k*k;
    while (n--) {
      a = b;
      b = c;
      c = (a+b)*(k-1);
    }
    return a;
  }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
};