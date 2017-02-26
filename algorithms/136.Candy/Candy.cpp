<<<<<<< HEAD
class Solution {
public:
int candy(vector<int> &ratings) {
    int Total = 0;    /// Total candies
    int length = 0;  /// Continuous descending length of rate
    int nPreCanCnt = 1; /// Previous child's candy count
    int beforeDenc = nPreCanCnt;
    if(ratings.begin() != ratings.end())
    {
        Total++; //Counting the first child's candy (1).
        for(vector<int>::iterator i = ratings.begin()+1; i!= ratings.end(); i++)
        {
            if(*i < *(i-1))
            {
                length++;
                if(beforeDenc <= length)
                {
                    Total++;
                }
                Total += length;
                nPreCanCnt = 1;    //This step is important, it ensures that once we leave the decending sequence, candy number start from 1
            }
            else
            {
                int curCanCnt = 0;
                if(*i > *(i-1))
                { 
                    curCanCnt = (nPreCanCnt + 1);
                }
                else
                {
                    curCanCnt = 1;
                }
                Total += curCanCnt;
                nPreCanCnt = curCanCnt;
                length = 0;    //reset length of decending sequence
                beforeDenc = curCanCnt;
            }
        }
    }
    return Total;
}
};
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size());

        candies[0] = 1;
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            } else {
                candies[i] = 1;
            }
        }
        
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
        
        int sum = 0;
        for (int i = 0; i < candies.size(); i++) {
            sum += candies[i];
        }
        
        return sum;
    }
=======
class Solution {
public:
int candy(vector<int> &ratings) {
    int Total = 0;    /// Total candies
    int length = 0;  /// Continuous descending length of rate
    int nPreCanCnt = 1; /// Previous child's candy count
    int beforeDenc = nPreCanCnt;
    if(ratings.begin() != ratings.end())
    {
        Total++; //Counting the first child's candy (1).
        for(vector<int>::iterator i = ratings.begin()+1; i!= ratings.end(); i++)
        {
            if(*i < *(i-1))
            {
                length++;
                if(beforeDenc <= length)
                {
                    Total++;
                }
                Total += length;
                nPreCanCnt = 1;    //This step is important, it ensures that once we leave the decending sequence, candy number start from 1
            }
            else
            {
                int curCanCnt = 0;
                if(*i > *(i-1))
                { 
                    curCanCnt = (nPreCanCnt + 1);
                }
                else
                {
                    curCanCnt = 1;
                }
                Total += curCanCnt;
                nPreCanCnt = curCanCnt;
                length = 0;    //reset length of decending sequence
                beforeDenc = curCanCnt;
            }
        }
    }
    return Total;
}
};
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size());

        candies[0] = 1;
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            } else {
                candies[i] = 1;
            }
        }
        
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
        
        int sum = 0;
        for (int i = 0; i < candies.size(); i++) {
            sum += candies[i];
        }
        
        return sum;
    }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
};