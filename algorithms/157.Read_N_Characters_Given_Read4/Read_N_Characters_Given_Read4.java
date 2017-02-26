<<<<<<< HEAD
/* The read4 API is defined in the parent class Reader4.
      int read4(char[] buf); */

public class ReadNCharactersGivenRead4 extends Reader4 {
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    public int read(char[] buf, int n) {
        int index = 0;
        char[] str = new char[4];
        int length = read4(str);
        while (length != 0 && index != n) {
            System.arraycopy( str, 0, buf, index, Math.min(n - index, length));
            index += Math.min(n - index, length);
            length = read4(str);
        }
        return index;
    }
=======
/* The read4 API is defined in the parent class Reader4.
      int read4(char[] buf); */

public class ReadNCharactersGivenRead4 extends Reader4 {
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    public int read(char[] buf, int n) {
        int index = 0;
        char[] str = new char[4];
        int length = read4(str);
        while (length != 0 && index != n) {
            System.arraycopy( str, 0, buf, index, Math.min(n - index, length));
            index += Math.min(n - index, length);
            length = read4(str);
        }
        return index;
    }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
}