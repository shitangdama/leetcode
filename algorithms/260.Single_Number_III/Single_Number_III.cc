<<<<<<< HEAD
class Solution {  
public:  
    vector<int> singleNumber(vector<int>& nums) {  
        int len = nums.size();  
        int AxorB = 0;  
        for(int i = 0; i < len; i++){  
            AxorB ^= nums[i];  
        }  
        int mask = AxorB & (~(AxorB - 1));  
        int A = 0;  
        int B = 0;  
        for(int i = 0; i < len; i++){  
            if((mask & nums[i]) == 0){  
                A ^= nums[i];  
            }else{  
                B ^= nums[i];  
            }  
        }  
        return vector<int>{A, B};  
    }  
=======
class Solution {  
public:  
    vector<int> singleNumber(vector<int>& nums) {  
        int len = nums.size();  
        int AxorB = 0;  
        for(int i = 0; i < len; i++){  
            AxorB ^= nums[i];  
        }  
        int mask = AxorB & (~(AxorB - 1));  
        int A = 0;  
        int B = 0;  
        for(int i = 0; i < len; i++){  
            if((mask & nums[i]) == 0){  
                A ^= nums[i];  
            }else{  
                B ^= nums[i];  
            }  
        }  
        return vector<int>{A, B};  
    }  
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
};