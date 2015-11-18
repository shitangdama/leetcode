// Group Shifted Strings
class Solution {
  string f(string s) {
    char c = s[0];
    for (auto &i: s)
      if (i-c < 0)
        i = i-c+26;
      else
        i -= c;
    return s;
  }
public:
  vector<vector<string>> groupStrings(vector<string>& strings) {
    vector<vector<string>> r;
    unordered_map<string, vector<string>> m;
    for (auto &s: strings)
      m[f(s)].push_back(s);
    for (auto &i: m) {
      sort(i.second.begin(), i.second.end());
      r.push_back(i.second);
    }
    return r;
  }
};
/*
249. Group Shifted Strings
Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:
"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.
For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
Return:
[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
Note: For the return value, each inner list's elements must follow the lexicographic order.
*/

class Solution {
private:
    bool isMatch(vector<vector<string>>& res, string str, int idx) {
        if(res[idx][0].size() != str.size()) return false;
        if(str.size() == 0) return true;
        int diff = (res[idx][0][0] - str[0] + 26) % 26;
        for(int i = 0; i < str.size(); i++) {
            int tmp_diff = (res[idx][0][i] - str[i] + 26) % 26;
            if(tmp_diff != diff) {
                return false;
            }
        }
        
        return true;
    }

public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        vector<string> record;
        int n = strings.size();
        if(n == 0) return res;
        record.push_back(strings[0]);
        res.push_back(record);
        for(int i = 1; i < n; i++) {
            bool found = false;
            for(int j = 0; j < res.size(); j++) {
                if(isMatch(res, strings[i], j)) {
                    res[j].push_back(strings[i]);
                    found = true;
                    break;
                }
            }
            if(!found) {
                record.clear();
                record.push_back(strings[i]);
                res.push_back(record);
            }
        }

        for(int i = 0; i < res.size(); i++) {
            sort(res[i].begin(), res[i].end());
        }
        
        return res;
    }
};
class Solution {

 public:
  string getKey(string s) {
    if(s.size() == 0) return "";
    int delta = s[0] - 'a';
    for(int i = 0; i < s.size(); ++i) {
      if(s[i] - delta >= 'a') {
        s[i] = s[i] - delta;
      } else {
        s[i] = s[i] - delta + 26;
      }
    }
    return s;
  }

  // ¿‡À∆anagrams
  vector<vector<string>> groupStrings(vector<string>& strings) {
    vector<vector<string>> groups;
    if(strings.size() == 0) return groups;
    unordered_set<string> S;
    unordered_map<string, int> indxM;
    for(int i = 0; i < strings.size(); ++i) {
      string key = getKey(strings[i]);
      if(S.count(key)) {
        groups[indxM[key]].push_back(strings[i]);
      } else {
        indxM[key] = groups.size();
        groups.push_back(vector<string>{strings[i]});
        S.insert(key);
      }
    }
    for(auto & group : groups) sort(group.begin(), group.end());
    return groups;
  }
};