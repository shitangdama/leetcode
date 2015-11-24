int hIndex(vector<int>& citations) {
    if(citations.empty())
        return 0;
    int n = citations.size();
    vector<int> hash(n + 1, 0);
    for(int i = 0; i < n; ++i){
        if(citations[i] >= n)
            hash[n]++;
        else
            hash[citations[i]]++;
    }
    int paper = 0;
    for(int i = n; i >= 0; --i){
        paper += hash[i];
        if(paper >= i)
            return i;
    }
}
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int res = 0;
        sort(citations.begin(), citations.end());
        reverse(citations.begin(), citations.end());
        for(int i = 0; i < n; i++) {
            res = max(res, min(i + 1, citations[i]));
        }
        return res;
    }
};