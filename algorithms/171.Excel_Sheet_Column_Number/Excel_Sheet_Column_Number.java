public class Solution {
    public int titleToNumber(String s) {
        
    	// from 26 to 10
    	int result = 0;
    	
    	for (int i=0; i<s.length(); i++) {
    		result = ((int)s.charAt(i)-(int)'A'+1)+26*result;
    	}
    	
    	return result;
    }
}