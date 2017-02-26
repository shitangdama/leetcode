public class WordDistance {
    
    HashMap<String, List<Integer>> map = new HashMap<String, List<Integer>>();
    
    public WordDistance(String[] words) {
        // ͳ��ÿ�����ʳ��ֵ��±�����ϣ����
        for(int i = 0; i < words.length; i++){
            List<Integer> cnt = map.get(words[i]);
            if(cnt == null){
                cnt = new ArrayList<Integer>();
            }
            cnt.add(i);
            map.put(words[i], cnt);
        }
    }

    public int shortest(String word1, String word2) {
        List<Integer> idx1 = map.get(word1);
        List<Integer> idx2 = map.get(word2);
        int distance = Integer.MAX_VALUE;
        int i = 0, j = 0;
        // ÿ�αȽ������±��б���С���±꣬Ȼ���������С���Ǹ�
        while(i < idx1.size() && j < idx2.size()){
            distance = Math.min(Math.abs(idx1.get(i) - idx2.get(j)), distance);
            if(idx1.get(i) < idx2.get(j)){
                i++;
            } else {
                j++;
            }
        }