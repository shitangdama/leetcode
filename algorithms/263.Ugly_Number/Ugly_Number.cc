<<<<<<< HEAD
class Solution {
public:
    bool isUgly(int num) {
        for (int i=2; i<6 && num; i++)
            while (num % i == 0)
                num /= i;
        return num == 1;
    }
=======
class Solution {
public:
    bool isUgly(int num) {
        for (int i=2; i<6 && num; i++)
            while (num % i == 0)
                num /= i;
        return num == 1;
    }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
};