<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;

        vector<char> mp(300);
        vector<bool> vis(300);
        for (int i = 0; i < s.length(); ++i) {
            if (mp[s[i]]) {
                if (mp[s[i]] != t[i])
                    return false;
            } else {
                // char in t is visited
                if (vis[t[i]])
                    return false;

                mp[s[i]] = t[i]; 
                vis[t[i]] = 1;
            }
        }

        return true;
    }
};
class Solution {

 public:
  bool foo(string s, string t) {
    unordered_map<char, char> M;
    for(int i = 0; i < s.size(); ++i) {
      if(M.count(s[i]) && M[s[i]] != t[i]) return false;
      M[s[i]] = t[i];
    }
    return true;
  }

  bool isIsomorphic(string s, string t) {
    if(s.size() != t.size()) return false;
    return foo(s, t) && foo(t, s);
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
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;

        vector<char> mp(300);
        vector<bool> vis(300);
        for (int i = 0; i < s.length(); ++i) {
            if (mp[s[i]]) {
                if (mp[s[i]] != t[i])
                    return false;
            } else {
                // char in t is visited
                if (vis[t[i]])
                    return false;

                mp[s[i]] = t[i]; 
                vis[t[i]] = 1;
            }
        }

        return true;
    }
};
class Solution {

 public:
  bool foo(string s, string t) {
    unordered_map<char, char> M;
    for(int i = 0; i < s.size(); ++i) {
      if(M.count(s[i]) && M[s[i]] != t[i]) return false;
      M[s[i]] = t[i];
    }
    return true;
  }

  bool isIsomorphic(string s, string t) {
    if(s.size() != t.size()) return false;
    return foo(s, t) && foo(t, s);
  }
};

int main() {

    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
