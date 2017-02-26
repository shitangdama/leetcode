<<<<<<< HEAD
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> s;
        for (auto a : nums) {
            if (s.find(a) != s.end()) continue;
            s.insert(a);
            auto it = s.upper_bound(a);
            if (it != s.end()) s.erase(it);
        }
        return s.size();
    }
=======
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> s;
        for (auto a : nums) {
            if (s.find(a) != s.end()) continue;
            s.insert(a);
            auto it = s.upper_bound(a);
            if (it != s.end()) s.erase(it);
        }
        return s.size();
    }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
};