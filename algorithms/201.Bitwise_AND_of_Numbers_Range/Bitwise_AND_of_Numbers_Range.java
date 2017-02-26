public class Solution {
    public int rangeBitwiseAnd(int m, int n) {
        if (n == m) {
            return n;
        }
        if (n - m == 1) {
            return n & m;
        }
        return rangeBitwiseAnd(m / 2, n / 2) << 1;
    }
}