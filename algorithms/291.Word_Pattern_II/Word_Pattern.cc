<<<<<<< HEAD

class Solution {
    map<char, string> pMap;
    map<string, char> sMap;
public:
    bool wordPatternMatch(string pattern, string str) {
        if(pattern.empty()) return str.empty();
        if(pMap.count(pattern[0])){
            string value = pMap[pattern[0]];
            if(str.size()<value.size() || (str.substr(0, value.size()) != value)) return false;
            return wordPatternMatch(pattern.substr(1), str.substr(value.size()));
        }
        else{
            for(int i = 1; i <= str.size(); i++){
                string newValue = str.substr(0, i);
                if(sMap.count(newValue)) continue;
                pMap[pattern[0]] = newValue;
                sMap[newValue] = pattern[0];
                if(wordPatternMatch(pattern.substr(1), str.substr(i))) return true;
                pMap.erase(pattern[0]);
                sMap.erase(newValue);
            }
        }
        
        return false;
    }
};


class Solution {
    unordered_map<char, string> pMap;
    unordered_map<string, char> sMap;
public:
    bool wordPatternMatch(string pattern, string str) {
        return dfs(pattern, 0, str, 0);
    }
    
    bool dfs(string &pattern, size_t pPattern, string &str, size_t pStr) {
        if(pattern.size() == pPattern) return str.size() == pStr;
        if(pattern.size() - pPattern > str.size() - pStr) return false;  // Pruning
        if(pMap.count(pattern[pPattern])){
            string value = pMap[pattern[pPattern]];
            if(str.size() - pStr <value.size() || (str.substr(pStr, value.size()) != value)) return false;
            return dfs(pattern, pPattern + 1, str, pStr + value.size());
        }
        else{
            for(int i = 1; i <= str.size() - pStr; i++){
                string newValue = str.substr(pStr, i);
                if(sMap.count(newValue)) continue;
                pMap[pattern[pPattern]] = newValue;
                sMap[newValue] = pattern[pPattern];
                if(dfs(pattern, pPattern + 1, str, pStr + i)) return true;
                sMap.erase(newValue);
            }
            pMap.erase(pattern[pPattern]); // This can be done outside the loop above
        }
        
        return false;
    }
=======

class Solution {
    map<char, string> pMap;
    map<string, char> sMap;
public:
    bool wordPatternMatch(string pattern, string str) {
        if(pattern.empty()) return str.empty();
        if(pMap.count(pattern[0])){
            string value = pMap[pattern[0]];
            if(str.size()<value.size() || (str.substr(0, value.size()) != value)) return false;
            return wordPatternMatch(pattern.substr(1), str.substr(value.size()));
        }
        else{
            for(int i = 1; i <= str.size(); i++){
                string newValue = str.substr(0, i);
                if(sMap.count(newValue)) continue;
                pMap[pattern[0]] = newValue;
                sMap[newValue] = pattern[0];
                if(wordPatternMatch(pattern.substr(1), str.substr(i))) return true;
                pMap.erase(pattern[0]);
                sMap.erase(newValue);
            }
        }
        
        return false;
    }
};


class Solution {
    unordered_map<char, string> pMap;
    unordered_map<string, char> sMap;
public:
    bool wordPatternMatch(string pattern, string str) {
        return dfs(pattern, 0, str, 0);
    }
    
    bool dfs(string &pattern, size_t pPattern, string &str, size_t pStr) {
        if(pattern.size() == pPattern) return str.size() == pStr;
        if(pattern.size() - pPattern > str.size() - pStr) return false;  // Pruning
        if(pMap.count(pattern[pPattern])){
            string value = pMap[pattern[pPattern]];
            if(str.size() - pStr <value.size() || (str.substr(pStr, value.size()) != value)) return false;
            return dfs(pattern, pPattern + 1, str, pStr + value.size());
        }
        else{
            for(int i = 1; i <= str.size() - pStr; i++){
                string newValue = str.substr(pStr, i);
                if(sMap.count(newValue)) continue;
                pMap[pattern[pPattern]] = newValue;
                sMap[newValue] = pattern[pPattern];
                if(dfs(pattern, pPattern + 1, str, pStr + i)) return true;
                sMap.erase(newValue);
            }
            pMap.erase(pattern[pPattern]); // This can be done outside the loop above
        }
        
        return false;
    }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
};