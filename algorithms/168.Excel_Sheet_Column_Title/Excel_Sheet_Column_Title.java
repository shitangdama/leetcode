

import java.util.Scanner;

public class Solution {

    public String convertToTitle(int n) {
        StringBuilder ret = new StringBuilder();
        while (n > 0) {
            ret.append((char)('A' + (n - 1) % 26));
            n = (n - 1) / 26;
        }
        return ret.reverse().toString();
    }

    // debug
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        Solution s = new Solution();
        System.out.println(s.convertToTitle(26));
    }

}
/* Excel Sheet Column Title */
/* O£¨1£©space
 * O(log26(N)) time
 */
public class Solution {
    public String convertToTitle(int n) {
        if (n <= 0) return "";
        
        StringBuilder builder = new StringBuilder();
        
        while ( n > 0) {
        	if ( n <= 26) {
        		builder.insert(0, (char)('A' + (n-1)));
        		break;
        	} else {
        		int v = (n-1) % 26;
           		builder.insert(0, (char)('A' + v));
           	    n = (n-1)/26;
        	}
        	
        }
        
        return builder.toString();
    }
    
    
    public String convertToTitle2(int n) {
        if (n <= 0) return "";
        
        StringBuilder builder = new StringBuilder();
        
        while ( n > 0) {
       		int v = (n-1) % 26;
       		builder.insert(0, (char)('A' + v));
       	    n = (n-1)/26;
        }
        
        return builder.toString();
    }
    
    
}