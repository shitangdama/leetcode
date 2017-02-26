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
};