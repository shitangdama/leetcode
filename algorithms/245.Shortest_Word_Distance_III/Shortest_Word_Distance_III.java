public class Solution {
    public int shortestWordDistance(String[] words, String word1, String word2) {
        int idx1 = -1, idx2 = -1, distance = Integer.MAX_VALUE, turn = 0, inc = (word1.equals(word2) ? 1 : 0);
        for(int i = 0; i < words.length; i++){
            if(words[i].equals(word1) && turn % 2 == 0){
                idx1 = i;
                if(idx2 != -1) distance = Math.min(distance, idx1 - idx2);
                turn += inc;
            } else if(words[i].equals(word2)){
                idx2 = i;
                if(idx1 != -1) distance = Math.min(distance, idx2 - idx1);
                turn += inc;
            }
        }
        return distance;
    }
}