// version 1:
public class Solution {
    public int singleNumberII(int[] A) {
        if (A == null || A.length == 0) {
            return -1;
        }
        
        // get the power of 3
        int[] pow3 = new int[20];
        pow3[0] = 1;
        for (int i = 1; i < 20; i++) {
            pow3[i] = pow3[i - 1] * 3;
        }
        
        // at most 20 bits for base 3 in maxint
        int[] bits = new int[20]; 
        
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < A.length; j++) {
                bits[i] += A[j] / pow3[i] % 3;
            }
        }
        
        // convert to decimal
        int result = 0;
        for (int i = 0; i < 20; i++) {
            result += pow3[i] * (bits[i] % 3);
        }
        return result;
    }
}

// version 2:
public class Solution {
    public int singleNumber(int[] A) {
        if (A == null || A.length == 0) {
            return -1;
        }
        int result=0;
        int[] bits=new int[32];
        for (int i = 0; i < 32; i++) {
            for(int j = 0; j < A.length; j++) {
                bits[i] += A[j] >> i & 1;
                bits[i] %= 3;
            }

            result |= (bits[i] << i);
        }
        return result;
    }
}
