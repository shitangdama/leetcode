public class Solution {

    public String shortestPalindrome(String s) {

        int j = 0;

        for (int i = s.length() - 1; i >= 0; i--) {//找到第一个使他不回文的位置

           if (s.charAt(i) == s.charAt(j)) { 

               j += 1; 

           }

        }

        if (j == s.length()) {  //本身是回文

            return s; 

        }

        String suffix = s.substring(j); // 后缀不能够匹配的字符串

        String prefix = new StringBuilder(suffix).reverse().toString(); // 前面补充prefix让他和suffix回文匹配

        String mid = shortestPalindrome(s.substring(0, j)); //递归调用找 [0,j]要最少可以补充多少个字符让他回文

        String ans = prefix + mid  + suffix;

        return  ans;

    }

}