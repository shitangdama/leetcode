public class Solution {
    public int shortestDistance(String[] words, String word1, String word2) {
        int i=-1, j=-1;
        int min = Integer.MAX_VALUE;
        for(int k=0; k<words.length; k++) {
            if(words[k].equals(word1) ) {
                if(j!=-1 && i==-1) {
                    min = k - j;
                } else {
                    min = Math.min(min, k-j);
                }
                i = k;
            } else if(words[k].equals(word2)){
                if(i!=-1 && j==-1) {
                    min = k - i;
                } else {
                    min = Math.min(min, k-i);
                }
                j = k;
            }
        }        
        return min;
    }
}
public class Solution {
    public int shortestDistance(String[] words, String word1, String word2) {
        int idx1 = -1, idx2 = -1, distance = Integer.MAX_VALUE;
        for(int i = 0; i < words.length; i++){
            if(words[i].equals(word1)){
                idx1 = i;
                // 第一次写入idx就先不比较
                if(idx2 != -1) distance = Math.min(distance, idx1 - idx2);
            }
            if(words[i].equals(word2)){
                idx2 = i;
                // 第一次写入idx就先不比较
                if(idx1 != -1) distance = Math.min(distance, idx2 - idx1);
            }
        }
        return distance;
    }
}