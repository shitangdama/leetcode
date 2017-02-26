<<<<<<< HEAD

public class Solution {

    boolean isIsomorphic(char[] S, char[] T) {
        char[] MAP = new char[256];

        for(int i = 0; i < S.length; i++) {

            if(MAP[(int)S[i]] == 0) {
                // not mapped
                MAP[(int)S[i]] = T[i];
            } else {

                if ( MAP[(int)S[i]] != T[i]) {
                    return false;
                }
            }

        }

        return true;
    }

    public boolean isIsomorphic(String s, String t) {

        char[] S = s.toCharArray();
        char[] T = t.toCharArray();

        if(S.length != T.length) return false;

        return isIsomorphic(S, T) && isIsomorphic(T, S);

    }
=======

public class Solution {

    boolean isIsomorphic(char[] S, char[] T) {
        char[] MAP = new char[256];

        for(int i = 0; i < S.length; i++) {

            if(MAP[(int)S[i]] == 0) {
                // not mapped
                MAP[(int)S[i]] = T[i];
            } else {

                if ( MAP[(int)S[i]] != T[i]) {
                    return false;
                }
            }

        }

        return true;
    }

    public boolean isIsomorphic(String s, String t) {

        char[] S = s.toCharArray();
        char[] T = t.toCharArray();

        if(S.length != T.length) return false;

        return isIsomorphic(S, T) && isIsomorphic(T, S);

    }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
}