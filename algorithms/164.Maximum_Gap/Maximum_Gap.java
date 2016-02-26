public class MaximumGap {
    public int maximumGap(int[] num) {
        if (num == null || num.length < 2) {
        	return 0;
        }
        
        Arrays.sort(num);
        
        int gap = num[1] - num[0];
        
        for (int i = 2; i < num.length; i ++) {
        	gap = Math.max(gap, num[i] - num[i - 1]);
        }
        
        return gap;
    }
}