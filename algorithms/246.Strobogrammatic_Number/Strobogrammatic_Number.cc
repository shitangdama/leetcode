<<<<<<< HEAD
// Strobogrammatic Number
class Solution {
public:
  bool isStrobogrammatic(string num) {
    const char *i = num.c_str(), *j = num.c_str()+num.size()-1;
    for (; i <= j; i++, j--) {
      int t = (*i-'0') * (*j-'0');
      if (! (*i == '0' && *j == '0' || t == 1 || t == 54 || t == 64))
        return false;
    }
    return true;
  }
=======
// Strobogrammatic Number
class Solution {
public:
  bool isStrobogrammatic(string num) {
    const char *i = num.c_str(), *j = num.c_str()+num.size()-1;
    for (; i <= j; i++, j--) {
      int t = (*i-'0') * (*j-'0');
      if (! (*i == '0' && *j == '0' || t == 1 || t == 54 || t == 64))
        return false;
    }
    return true;
  }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
};