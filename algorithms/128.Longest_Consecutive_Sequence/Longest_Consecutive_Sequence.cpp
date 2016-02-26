// Leet Code, Longest Consecutive Sequence
// 时间复杂度O(n)，空间复杂度O(n)
// Author: @advancedxy
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> map;
        int size = num.size();
        int l = 1;
        for (int i = 0; i < size; i++) {
            if (map.find(num[i]) != map.end()) continue;
            map[num[i]] = 1;
            if (map.find(num[i] - 1) != map.end()) {
                l = max(l, mergeCluster(map, num[i] - 1, num[i]));
            }
            if (map.find(num[i] + 1) != map.end()) {
                l = max(l, mergeCluster(map, num[i], num[i] + 1));
            }
        }
        return size == 0 ? 0 : l;
    }

private:
    int mergeCluster(unordered_map<int, int> &map, int left, int right) {
        int upper = right + map[right] - 1;
        int lower = left - map[left] + 1;
        int length = upper - lower + 1;
        map[upper] = length;
        map[lower] = length;
        return length;
    }
};

class Solution {
public:
    int longestConsecutive(const vector<int> &num) {
        unordered_map<int, bool> used;

        for ( auto i : num) used[i] = false;

        int longest = 0;

        for (auto i : num) {
            if (used[i]) continue;

            int length = 1;

            used[i] = true;

            for (int j = i + 1; used.find(j) != used.end(); ++j) {
                used[j] = true;
                ++length;
            }

            for (int j = i - 1; used.find(j) != used.end(); --j) {
                used[j] = true;
                ++length;
            }

            longest = max(longest, length);
        }

        return longest;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> hash;
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]] = true;
        }
        
        int max = 0;
        for (int i = 0; i < nums.size(); i++) {
            int up = nums[i];
            while (hash.find(up) != hash.end()) {
                hash.erase(up);
                up++;
            }
            int down = nums[i] - 1;
            while (hash.find(down) != hash.end()) {
                hash.erase(down);
                down--;
            }
            if (up - down - 1 > max) {
                max = up - down - 1;
            }
        }
        return max;
    }
};