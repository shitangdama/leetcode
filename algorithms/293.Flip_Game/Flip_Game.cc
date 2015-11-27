class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> result;
        for(int i = 0; i < (int)s.size() - 1; i++) {
            if(s[i] == s[i+1] && s[i] == '+'){
                string t = s;
                t[i] = t[i+1] = '-';
                result.push_back(t);
            }
        }
        return result;
    }
};

// Flip Game
class Solution {
public:
  vector<string> generatePossibleNextMoves(string s) {
    vector<string> r;
    for (int i = 0; i+1 < s.size(); i++)
      if (s[i] == '+' && s[i+1] == '+') {
        r.push_back(s);
        r.back()[i] = '-';
        r.back()[i+1] = '-';
      }
    return r;
  }
};