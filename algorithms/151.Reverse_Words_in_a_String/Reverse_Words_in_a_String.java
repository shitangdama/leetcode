public class Solution {
    public String reverseWords(String s) {
        if (s == null || s.length() == 0) {
            return "";
        }

        String[] array = s.split(" ");
        StringBuilder sb = new StringBuilder();

        for (int i = array.length - 1; i >= 0; --i) {
            if (!array[i].equals("")) {
                sb.append(array[i]).append(" ");
            }
        }

        //remove the last " "
        return sb.length() == 0 ? "" : sb.substring(0, sb.length() - 1);
    }
}
public class Solution {
    public String reverseWords(String s) {
        String[] words = s.trim().split(" +");
        int len = words.length;
        if (len == 0) {
            return "";
        }
        StringBuilder sb = new StringBuilder(words[len - 1]);
        for (int i = len - 2; i >= 0; --i) {
            sb.append(" " + words[i]);
        }
        return sb.toString();}
}