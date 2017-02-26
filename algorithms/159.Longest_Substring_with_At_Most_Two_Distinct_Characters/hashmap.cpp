#include <bits/stdc++.h>

int lengthOfLongestSubstringTwoDistinct(string s) {
    int maxLen = 0;
    int charMap[256] = {0};
    int wordCnt = 0;
    int start = 0;

    for(int i=0; i<s.size(); i++){
        if ( charMap[s[i]]++ == 0 ){
            wordCnt++;
        }
        while (wordCnt>2){
            charMap[s[start]]--;
            if (charMap[s[start]]==0){
                wordCnt--;
            }
            start++;
        }
        maxLen = max(maxLen, i - start + 1);
    }

    return maxLen;
}class LongestSubstringwithAtMostTwoDistinctCharacters {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> map;
        int start = 0, max_len = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (map.size() == 2 && map.find(s[i]) == map.end()) {
                for (auto& pair : map) {
                    if (pair.first != s[i - 1]) {
                        start = pair.second + 1;
                        map.erase(pair.first);
                        break;
                    }
                }
            }
            map[s[i]] = i;
            max_len = max(max_len, i - start + 1);
        }

        return max_len;
    }
};

int main() {

    return 0;
}

