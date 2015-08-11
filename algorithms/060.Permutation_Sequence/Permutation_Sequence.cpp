class Solution {
public:
string getPermutation(int n, int k) {
        vector<int>num(n);
		int permCount = 1;
		for(int i=0;i<n;i++){
			num[i] = i+1;
			permCount*=(i+1);
		}
		k--;
		string target;
		for(int i=0;i<n;i++){
			permCount = permCount/(n-i);
			int choosed = k/permCount;
			target.push_back(num[choosed]+'0');
			for(int j=choosed;j<n-i;j++){
				num[j] = num[j+1];
			}
			k = k%permCount;
		}
		return target;
    }
};