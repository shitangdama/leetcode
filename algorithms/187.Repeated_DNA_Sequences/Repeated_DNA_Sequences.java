import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Solution {

    private int get_value(char ch) {
        switch (ch) {
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
        }
        return -1;
    }

    public List<String> findRepeatedDnaSequences(String s) {
        List<String> ans = new ArrayList<String>();
        boolean appeared[] = new boolean[11000000];
        boolean used[] = new boolean[11000000];
        if (s.length() <= 10)
            return ans;

        int hash = 0;
        // get first substring's hash
        for (int i = 0; i < 10; i++)
            hash = (hash << 2) | get_value(s.charAt(i));
        appeared[hash] = true;

        // deal every substring
        for (int i = 10; i < s.length(); ++i) {
            hash = ((1<<20) - 1) & ((hash << 2) | get_value(s.charAt(i)));
            if (used[hash])
                continue;
            if (appeared[hash]) {
                ans.add(s.substring(i - 9, i + 1));
                used[hash] = true;
            } else
                appeared[hash] = true;
        }

        return ans;
    }

    // debug
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        Solution s = new Solution();
        int[] input = {1, 2, 3, 1};
        System.out.println(s.findRepeatedDnaSequences("AAAAAAAAAAAA"));
    }
}

public class Solution {
    public int encode(String s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'A') {
                sum = sum * 4;
            } else if (s.charAt(i) == 'C') {
                sum = sum * 4 + 1;
            } else if (s.charAt(i) == 'G') {
                sum = sum * 4 + 2;
            } else {
                sum = sum * 4 + 3;
            }
        }
        return sum;
    }
    public List<String> findRepeatedDnaSequences(String s) {
        HashSet<Integer> hash = new HashSet<Integer>();
        HashSet<String> dna = new HashSet<String>();
        for (int i = 9; i < s.length(); i++) {
            String subString = s.substring(i - 9, i + 1);
            int encoded = encode(subString);
            if (hash.contains(encoded)) {
                dna.add(subString);
            } else {
                hash.add(encoded);
            }
        }
        List<String> result = new ArrayList<String>();
        for (String d: dna) {
            result.add(d);
        }
        return result;
    }
}
