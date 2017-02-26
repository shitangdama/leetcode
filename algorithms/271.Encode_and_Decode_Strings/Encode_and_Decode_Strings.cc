<<<<<<< HEAD
// Encode and Decode Strings
class Codec {
public:

  // Encodes a list of strings to a single string.
  string encode(vector<string>& strs) {
    string r;
    for (auto &s: strs)
      r += to_string(s.size())+':'+s;
    return r;
  }

  // Decodes a single string to a list of strings.
  vector<string> decode(string s) {
    vector<string> r;
    for (int l, j, i = 0; i < s.size(); i = j+1+l) {
      j = s.find(':', i);
      l = stoi(s.substr(i, j-i), NULL);
      r.push_back(s.substr(j+1, l));
    }
    return r;
  }
};
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for (auto str : strs) {
            res += to_string(str.length()) + "#" + str;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int idx = 0, pos, size;
        while (idx < s.length()) {
            pos = s.find('#', idx);
            if (pos == string::npos) break;
            size = stoi(s.substr(idx, pos-idx));
            res.push_back(s.substr(pos+1, size));
            idx = pos + 1 + size;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
=======
// Encode and Decode Strings
class Codec {
public:

  // Encodes a list of strings to a single string.
  string encode(vector<string>& strs) {
    string r;
    for (auto &s: strs)
      r += to_string(s.size())+':'+s;
    return r;
  }

  // Decodes a single string to a list of strings.
  vector<string> decode(string s) {
    vector<string> r;
    for (int l, j, i = 0; i < s.size(); i = j+1+l) {
      j = s.find(':', i);
      l = stoi(s.substr(i, j-i), NULL);
      r.push_back(s.substr(j+1, l));
    }
    return r;
  }
};
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for (auto str : strs) {
            res += to_string(str.length()) + "#" + str;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int idx = 0, pos, size;
        while (idx < s.length()) {
            pos = s.find('#', idx);
            if (pos == string::npos) break;
            size = stoi(s.substr(idx, pos-idx));
            res.push_back(s.substr(pos+1, size));
            idx = pos + 1 + size;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
// codec.decode(codec.encode(strs));