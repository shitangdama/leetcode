#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // use unordered_set as queue
        unordered_set<string> startSet, endSet, *set1, *set2;

        startSet.insert(start);
        endSet.insert(end);
        int dis = 1, len = start.length();
        while (!startSet.empty() && !endSet.empty()) {
            if (startSet.size() > endSet.size()) {
                set1 = &startSet;
                set2 = &endSet;
            } else {
                set1 = &endSet;
                set2 = &startSet;
            }

            ++dis;

            unordered_set<string> newset1;
            for (auto itr = set1->begin(); itr != set1->end(); itr++) {
                string old = *itr;
                for (int i = 0; i < len; ++i) {
                    char tmp = old[i];
                    for (int j = 0; j < 26; ++j) {
                        old[i] = 'a' + j;
                        auto f = set2->find(old);
                        if (f != set2->end())
                            return dis;
                        f = dict.find(old);
                        if (f != dict.end()) {
                            newset1.insert(old);
                            dict.erase(f);
                        }
                    }
                    old[i] = tmp;
                }
            }
            swap(newset1, *set1);
        }
        return 0;
    }
};
class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start == end) {
            return 1;
        }
        int n = start.size();
        if (n < 1 || n != end.size()) {
            return 0;
        }
 
        queue<string> Q;
        Q.push(start);
        dict.erase(start);
        int length = 2;
 
        while (!Q.empty()) {
            int size = Q.size();
            for (int i = 0; i < size; i++) {
                string word = Q.front(); Q.pop();
                for (int i = 0; i < n; i++) {
                    char oldChar = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == oldChar) continue;
                        word[i] = c;
                        if (word == end) {
                            return length;
                        }
                        if (dict.find(word) != dict.end()) {
                            Q.push(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = oldChar;
                }
            } // for size
            length++;
        }
        return 0;
    }
};

int main() {

    return 0;
}

