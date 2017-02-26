

import java.util.*;

public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int ret = 0;
        while (n != 0) {
            if ((n&1) == 1) {
                ret++;
            }
            n >>>= 1;
        }
        return ret;
    }

<<<<<<< HEAD
   
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        if (n == 0) {
            return 0;
        }
        
        int count = 1;
        while ((n & (n - 1)) != 0) {
            n &= n-1;
            count++;
        }
        return count;
    }
}

=======
   
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        if (n == 0) {
            return 0;
        }
        
        int count = 1;
        while ((n & (n - 1)) != 0) {
            n &= n-1;
            count++;
        }
        return count;
    }
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
 // debug
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        Solution s = new Solution();
        int[] input = {1, 2, 3, 4};
        System.out.println("no case");
    }
}
<<<<<<< HEAD

=======

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
