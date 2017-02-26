<<<<<<< HEAD
class Solution {

 public:
  string shortestPalindrome(string s) {
    if(s.size() == 0) return s;
    string extendS = s + "#" + string(s.rbegin(), s.rend());
    vector<int> prefix(extendS.size(), 0);
    for(int i = 1; i < extendS.size(); ++i) {
      int k = prefix[i-1];
      while(k > 0 && extendS[k] != extendS[i]) k = prefix[k-1];
      if(extendS[k] == extendS[i]) k += 1;
      prefix[i] = k;
    }
    string tmp = s.substr(prefix.back(), s.size() - prefix.back());
    return string(tmp.rbegin(), tmp.rend()) + s;
  }
=======
class Solution {

 public:
  string shortestPalindrome(string s) {
    if(s.size() == 0) return s;
    string extendS = s + "#" + string(s.rbegin(), s.rend());
    vector<int> prefix(extendS.size(), 0);
    for(int i = 1; i < extendS.size(); ++i) {
      int k = prefix[i-1];
      while(k > 0 && extendS[k] != extendS[i]) k = prefix[k-1];
      if(extendS[k] == extendS[i]) k += 1;
      prefix[i] = k;
    }
    string tmp = s.substr(prefix.back(), s.size() - prefix.back());
    return string(tmp.rbegin(), tmp.rend()) + s;
  }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
};