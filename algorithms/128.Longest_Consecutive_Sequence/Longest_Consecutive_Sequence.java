public class Solution {
    // Sort & search: space O(1), time O(n logn)
    // HashMap: space O(n), time O(n)
    public int longestConsecutive(int[] num) {
        HashMap<Integer, Integer> hs = new HashMap<Integer, Integer>();
        for(int i: num){
            hs.put(i, 0);
        }
        int maxl = 1;
        for(int i: num){
            if (hs.get(i) == 1) continue;

            int tmp = i;
            int current_max = 1;
            while(hs.containsKey(tmp+1)){
                current_max ++;
                tmp ++;
                hs.put(tmp, 1);
            }

            tmp = i;
            while(hs.containsKey(tmp-1)){
                current_max ++;
                tmp --;
                hs.put(tmp, 1);
            }

            maxl = Math.max(current_max, maxl);
        }

        return maxl;
    }
}