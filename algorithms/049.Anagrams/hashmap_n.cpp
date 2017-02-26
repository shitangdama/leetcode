#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> ans;
        map<string, vector<int> > rec;
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            rec[str].push_back(i);
        }
        for (auto &it : rec) {
            if (it.second.size() > 1) {
                for (auto &ind : it.second)
                    ans.push_back(strs[ind]);
            }
        }
        return ans;
    }
};

// LeetCode, Anagrams
// 时间复杂度O(n)，空间复杂度O(n)
class Solution2 {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string> > group;
        for (const auto &s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            group[key].push_back(s);
        }

        vector<string> result;
        for (auto it = group.cbegin(); it != group.cend(); it++) {
            if (it->second.size() > 1)
                result.insert(result.end(), it->second.begin(), it->second.end());
        }
        return result;
    }
};
class Solution3 {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    string getSortedString(string &str) {
        static int count[26];
        for (int i = 0; i < 26; i++) {
            count[i] = 0;
        }
        for (int i = 0; i < str.length(); i++) {
            count[str[i] - 'a']++;
        }
        
        string sorted_str = "";
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < count[i]; j++) {
                sorted_str = sorted_str + (char)('a' + i);
            }
        }
        return sorted_str;
    }
    
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, int> hash;
        
        for (int i = 0; i < strs.size(); i++) {
            string str = getSortedString(strs[i]);
            if (hash.find(str) == hash.end()) {
                hash[str] = 1;
            } else {
                hash[str] = hash[str] + 1;
            }
        }
        
        vector<string> result;
        for (int i = 0; i < strs.size(); i++) {
            string str = getSortedString(strs[i]);
            if (hash.find(str) == hash.end()) {
                continue;
            } else {
                if (hash[str] > 1) {
                    result.push_back(strs[i]);
                }
            }
        }
        return result;
    }
};


int main() {

    return 0;
}

