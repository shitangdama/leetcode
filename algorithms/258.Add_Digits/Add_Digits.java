public class Solution {
public int addDigits(int num) {
    int tmp = 0;
    while (num > 0) {
        tmp += num % 10;
        if (tmp >= 10) {
            tmp = tmp % 10 + tmp / 10;
        }
        num = num / 10;
    }
    return tmp;

}