import java.util.Comparator;
import java.util.Scanner;

public class Solution {

    public String largestNumber(int[] num) {
        String[] str = new String[num.length];
        for (int i = 0; i < num.length; ++i) {
            str[i] = num[i] + "";
        }

        Comparator<String> comp = new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return (o2 + o1).compareTo(o1 + o2);    // reverse
            }
        };

        Arrays.sort(str, comp);
        if (str[0].equals("0")) {
            return "0";
        }

        String ans = new String();
        for (String s : str)
            ans += s;

        return ans;
    }

    // debug
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        Solution s = new Solution();
        int[] input = {0, 0, 0};
        System.out.println(s.largestNumber(input));
    }
}
class NumbersComparator implements Comparator<String> {
	@Override
	public int compare(String s1, String s2) {
		return (s2 + s1).compareTo(s1 + s2);
	}
}

public class Solution {
    
    public String largestNumber(int[] nums) {
        String[] strs = new String[nums.length];
        for (int i = 0; i < nums.length; i++) {
            strs[i] = Integer.toString(nums[i]);
        }
        Arrays.sort(strs, new NumbersComparator());
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < strs.length; i++) {
            sb.append(strs[i]);
        }
        String result = sb.toString();
        int index = 0;
        while (index < result.length() && result.charAt(index) == '0') {
            index++;
        }
        if (index == result.length()) {
            return "0";
        }
        return result.substring(index);
    }
}