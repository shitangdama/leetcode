public class Solution {

	
	// Reverse the entire string, W1W2...Wn -> Wn'...W2'W1'
	// Then reverse individual words, Wn'...W2'W1' -> Wn...W2W1
	// O(n) runtime, O(1) space - In-place reverse
    public static void reverseWords( char[] s ) 
    {
	    reverse( s, 0, s.length );
	    
	    for( int i = 0, j = 0; j <= s.length; j++ )
	    {
	    	if ( j == s.length || s[j] == ' '  )
	    	{
	    		reverse( s, i, j );
	    		i = j+1;
	    	}
	    }
    }
    
    private static void reverse ( char[] s, int begin, int end )
    {
    	
    	for ( int i = 0; i < (end-begin)/2; i++ )
    	{
    		char temp = s[begin+i];
    		s[begin+i] = s[end-i-1];
    		s[end-i-1] = temp;
    	}
    }
    
	public static void main(String[] args) 
	{
		char[] chars1 = "the sky is blue".toCharArray();
		char[] chars2 = "I love to play a lot of games".toCharArray();
		reverseWords( chars1 );
		reverseWords( chars2 );
		System.out.println( String.valueOf( chars1 ) );
		System.out.println( String.valueOf( chars2 ) );
		
	}
}