public class Solution {

    public String shortestPalindrome(String s) {

        int j = 0;

        for (int i = s.length() - 1; i >= 0; i--) {//�ҵ���һ��ʹ�������ĵ�λ��

           if (s.charAt(i) == s.charAt(j)) { 

               j += 1; 

           }

        }

        if (j == s.length()) {  //�����ǻ���

            return s; 

        }

        String suffix = s.substring(j); // ��׺���ܹ�ƥ����ַ���

        String prefix = new StringBuilder(suffix).reverse().toString(); // ǰ�油��prefix������suffix����ƥ��

        String mid = shortestPalindrome(s.substring(0, j)); //�ݹ������ [0,j]Ҫ���ٿ��Բ�����ٸ��ַ���������

        String ans = prefix + mid  + suffix;

        return  ans;

    }

}