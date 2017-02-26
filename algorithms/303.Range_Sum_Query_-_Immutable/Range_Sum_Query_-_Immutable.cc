<<<<<<< HEAD
class NumArray {
private:
    vector<int> sum;
public:
    NumArray(vector<int> &nums) {   //constructor
    for(int i=0;i<nums.size();i++)
    {
        if(i==0) sum.push_back(nums[i]);
        else
        sum.push_back(sum.back()+nums[i]);
    }
    }

    int sumRange(int i, int j) {
        if(i==0) return sum[j];
        return sum[j]-sum[i-1];
    }
};
class NumArray {
public:
    NumArray(vector<int> &nums) {
        accu.push_back(0);
        for (int num : nums)
            accu.push_back(accu.back() + num);
    }

    int sumRange(int i, int j) {
        return accu[j + 1] - accu[i];
    }
private:
    vector<int> accu;
};
=======
class NumArray {
private:
    vector<int> sum;
public:
    NumArray(vector<int> &nums) {   //constructor
    for(int i=0;i<nums.size();i++)
    {
        if(i==0) sum.push_back(nums[i]);
        else
        sum.push_back(sum.back()+nums[i]);
    }
    }

    int sumRange(int i, int j) {
        if(i==0) return sum[j];
        return sum[j]-sum[i-1];
    }
};
class NumArray {
public:
    NumArray(vector<int> &nums) {
        accu.push_back(0);
        for (int num : nums)
            accu.push_back(accu.back() + num);
    }

    int sumRange(int i, int j) {
        return accu[j + 1] - accu[i];
    }
private:
    vector<int> accu;
};
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
