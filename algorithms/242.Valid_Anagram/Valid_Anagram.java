<<<<<<< HEAD
public class Solution {
   public boolean isAnagram(String s, String t) {
        if (s == null || t == null || s.length() != t.length()) return false;
        int[] map = new int[26];
        for (int i = 0; i < s.length(); i++)
            map[s.charAt(i) - 'a']++;
        for (int i = 0; i < t.length(); i++)
            if(--map[t.charAt(i) - 'a'] < 0)
                return false;
        return true;
    }

}
    public class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length()!=t.length()){
            return false;
        }
        int[] count = new int[26];
        for(int i=0;i<s.length();i++){
            count[s.charAt(i)-'a']++;
            count[t.charAt(i)-'a']--;
        }
        for(int i:count){
            if(i!=0){
                return false;
            }
        }
        return true;
    }
=======
public class Solution {
   public boolean isAnagram(String s, String t) {
        if (s == null || t == null || s.length() != t.length()) return false;
        int[] map = new int[26];
        for (int i = 0; i < s.length(); i++)
            map[s.charAt(i) - 'a']++;
        for (int i = 0; i < t.length(); i++)
            if(--map[t.charAt(i) - 'a'] < 0)
                return false;
        return true;
    }

}
    public class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length()!=t.length()){
            return false;
        }
        int[] count = new int[26];
        for(int i=0;i<s.length();i++){
            count[s.charAt(i)-'a']++;
            count[t.charAt(i)-'a']--;
        }
        for(int i:count){
            if(i!=0){
                return false;
            }
        }
        return true;
    }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
}