<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int> &num) {
        int len = num.size();
        if (len < 2) return 0;
        if (len == 2) return abs(num[0] - num[1]);
        int mmax = num[0], mmin = num[0];

        // find out the max, min
        for (auto i : num) {
            mmax = max(mmax, i);
            mmin = min(mmin, i);
        }
        if (mmin == mmax)
            return 0;

        // bucket sort
        int bucket_size = (mmax - mmin) / (len - 1);
        if (bucket_size <= 1)
            return mmax - mmin;
        int bucket_num = (mmax - mmin) / bucket_size + 1;
        vector<int> max_bucket(bucket_num, INT_MIN);
        vector<int> min_bucket(bucket_num, INT_MAX);
        for (auto i : num) {
            int j = (i - mmin) / bucket_size;
            max_bucket[j] = max(max_bucket[j], i);
            min_bucket[j] = min(min_bucket[j], i);
        }

        // solve
        int ret = 0;
        int last_max = mmin;    // this dosen't matter, because the max_gap will more large
        for (int i = 0; i < bucket_num; ++i) {
            if (max_bucket[i] != INT_MIN) {
                // there are some numbers
                ret = max(ret, min_bucket[i] - last_max);
                last_max = max_bucket[i];
            }
        }

        return ret;
    }
};

struct Block {
  int max, min;
};

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
      
        if (nums.size() < 2) {
            return 0;
        }
        int min = nums[0];
        int max = nums[0];
        for (int i = 1; i < nums.size(); i++) {
           min = min < nums[i] ? min : nums[i];
           max = max > nums[i] ? max : nums[i];
        }
        if (max == min) {
          return 0;
        }
        int block_size = (max - min - 1) / n + 1;
        cout << block_size << endl;
        vector<Block> blocks(n);
        for (int i = 0; i < n; i++) {
          blocks[i].max = blocks[i].min = -1;
        }
        for (int i = 0; i < n; i++) {
          int block_id = (nums[i] - min) / block_size;
          if (blocks[block_id].max == -1) {
            blocks[block_id].min = blocks[block_id].max = nums[i];
          } else {
            blocks[block_id].min = blocks[block_id].min < nums[i] ? blocks[block_id].min : nums[i];
            blocks[block_id].max = blocks[block_id].max > nums[i] ? blocks[block_id].max : nums[i];
          }
        }
      
        int maxGap = -1;
        int lastNumber = blocks[0].max;
        for (int i = 1; i < n; i++) {
          if (blocks[i].min == -1) {
            continue;
          }
          maxGap = maxGap > blocks[i].min - lastNumber ? maxGap : blocks[i].min - lastNumber;
          lastNumber = blocks[i].max;
        }
        return maxGap;
    }
};
class Solution {
public:
    int maximumGap(vector<int> &num) {
        if(num.empty() || num.size() < 2)
            return 0;
        sort(num.begin(), num.end());
        int maxGap = num[1]-num[0];
        for(int i = 2; i < num.size(); i ++)
        {
            int curGap = num[i]-num[i-1];
            maxGap = (maxGap>=curGap)?maxGap:curGap;
        }
        return maxGap;
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> num(n);
    for (auto &i :  num)
        cin >> i;
    Solution s;
    cout << s.maximumGap(num) << endl;
    return 0;
}

=======
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int> &num) {
        int len = num.size();
        if (len < 2) return 0;
        if (len == 2) return abs(num[0] - num[1]);
        int mmax = num[0], mmin = num[0];

        // find out the max, min
        for (auto i : num) {
            mmax = max(mmax, i);
            mmin = min(mmin, i);
        }
        if (mmin == mmax)
            return 0;

        // bucket sort
        int bucket_size = (mmax - mmin) / (len - 1);
        if (bucket_size <= 1)
            return mmax - mmin;
        int bucket_num = (mmax - mmin) / bucket_size + 1;
        vector<int> max_bucket(bucket_num, INT_MIN);
        vector<int> min_bucket(bucket_num, INT_MAX);
        for (auto i : num) {
            int j = (i - mmin) / bucket_size;
            max_bucket[j] = max(max_bucket[j], i);
            min_bucket[j] = min(min_bucket[j], i);
        }

        // solve
        int ret = 0;
        int last_max = mmin;    // this dosen't matter, because the max_gap will more large
        for (int i = 0; i < bucket_num; ++i) {
            if (max_bucket[i] != INT_MIN) {
                // there are some numbers
                ret = max(ret, min_bucket[i] - last_max);
                last_max = max_bucket[i];
            }
        }

        return ret;
    }
};

struct Block {
  int max, min;
};

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
      
        if (nums.size() < 2) {
            return 0;
        }
        int min = nums[0];
        int max = nums[0];
        for (int i = 1; i < nums.size(); i++) {
           min = min < nums[i] ? min : nums[i];
           max = max > nums[i] ? max : nums[i];
        }
        if (max == min) {
          return 0;
        }
        int block_size = (max - min - 1) / n + 1;
        cout << block_size << endl;
        vector<Block> blocks(n);
        for (int i = 0; i < n; i++) {
          blocks[i].max = blocks[i].min = -1;
        }
        for (int i = 0; i < n; i++) {
          int block_id = (nums[i] - min) / block_size;
          if (blocks[block_id].max == -1) {
            blocks[block_id].min = blocks[block_id].max = nums[i];
          } else {
            blocks[block_id].min = blocks[block_id].min < nums[i] ? blocks[block_id].min : nums[i];
            blocks[block_id].max = blocks[block_id].max > nums[i] ? blocks[block_id].max : nums[i];
          }
        }
      
        int maxGap = -1;
        int lastNumber = blocks[0].max;
        for (int i = 1; i < n; i++) {
          if (blocks[i].min == -1) {
            continue;
          }
          maxGap = maxGap > blocks[i].min - lastNumber ? maxGap : blocks[i].min - lastNumber;
          lastNumber = blocks[i].max;
        }
        return maxGap;
    }
};
class Solution {
public:
    int maximumGap(vector<int> &num) {
        if(num.empty() || num.size() < 2)
            return 0;
        sort(num.begin(), num.end());
        int maxGap = num[1]-num[0];
        for(int i = 2; i < num.size(); i ++)
        {
            int curGap = num[i]-num[i-1];
            maxGap = (maxGap>=curGap)?maxGap:curGap;
        }
        return maxGap;
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> num(n);
    for (auto &i :  num)
        cin >> i;
    Solution s;
    cout << s.maximumGap(num) << endl;
    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
