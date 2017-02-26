<<<<<<< HEAD
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
=======
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
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
}